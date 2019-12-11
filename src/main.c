// Server side implementation of UDP client-server model
// refference https://zserge.com/jsmn.html
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>
#include "../includes/handleMessage.h"
#include "../includes/output.h"
#include "../includes/tools.h"
#include "../includes//dbTools.h"
#include "../includes/semiBlockingQueue.h"

#define PORT    7777
#define MAXLINE 1500
#define NUM_OF_THREADS 3


pthread_t tid[NUM_OF_THREADS]; //{server,handleMessage,handleData}
//bsonData* incomingMessagesQueue=0;


const char *JSON_STRING ="{\"device\": \"Jack\", \"bson\": 27}";
// example {"device": "Jack", "bson":27}

/**
 * start thread number thread_n in the threads array
 * @param thread_n
 * @return 0 on success and non 0 value otherwise
 */
int start_thread(int thread_n){
    int ret;
    ret = pthread_create(&tid[thread_n],NULL,handleList,NULL);
    if(ret !=0){
        saveLog("EROOR while executing 'pthread_create' on handleList, received error no.",itoa(thread_n),"","","");
    }
    return ret;
}

/**
 * initialize the threads array of the server
 * @return 0 on success, non 0 on failure of one of the threads
 */
int init_threads(){
    int ret;
    tid[0] = pthread_self();
    for(int i=1;i<=NUM_OF_THREADS;i++){
        ret=start_thread(i);
        if(ret!=0) {
            return ret;
        }
    }
    return 0;
}


void initQueues() {
    incomingMessagesQueue=initSemiBlockingQueue();
    dataNodesQueue=initSemiBlockingQueue();
}

// Driver code
int main() {
    int sockfd;
    char buffer[MAXLINE];
    char *bufferPtr=buffer;
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    //Initializing the database
    init_db(1);
    initQueues();
    init_output();
    init_threads();

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *) &servaddr,
             sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }



    saveShortLog("Sarting server");

    int len, n;
   char* incomingMessage=NULL;
    while (1) {
        n = recvfrom(sockfd, (char *) buffer, MAXLINE,
                     MSG_WAITALL, (struct sockaddr *) &cliaddr,
                     &len);
        buffer[n] = '\0';
        printf("recived message: %s\n",bufferPtr);
        enqueue(incomingMessagesQueue, createMsgNode(bufferPtr));
//        printf("Client : %s\n", buffer);
//        sendto(sockfd, (const char *) hello, strlen(hello),
//               MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
//               len);
//        printf("Hello message sent. \n \n");
    }

}
//netcat -l localhost 7777 <<< "{"device": "Jack", "bson": 27}"
//echo "{\"device\": \"Jack\", \"bson\": 27}" > /dev/udp/127.0.0.1/7777
//watch -n 1 echo "{\"device\": \"Jack\", \"bson\": 27}" > /dev/udp/127.0.0.1/7777