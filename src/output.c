//
// Created by avicii on 5/5/19.
//
#include <time.h>
#include <stdio.h>
#include "../includes/output.h"

int outputfd=0;

int main_thread_waiting=0;
int list_thread_waiting=0;
long log_counter=0;
pthread_t main_tid,list_tid;
pthread_mutex_t saveLogLock;

void init_output(){
    if (pthread_mutex_init(&saveLogLock, NULL) != 0){
        printf("\n mutex init failed\n");
    }
}
void saveShortLog(char* str){
    saveLog(str,"","","","");
}
void saveLog(char* str1,char* str2,char* str3,char* str4, char* str5){
    while(pthread_mutex_lock(&saveLogLock)!=0){}

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );


    fprintf(outputfd,"LOG[%ld] %s\t:%s %s %s %s %s\n",log_counter,asctime (timeinfo),str1,str2,str3,str4,str5);
    log_counter++;
    while(pthread_mutex_lock(&saveLogLock)!=0){
        fprintf(outputfd,"LOG[%ld] %s\t: thread [%d] failed to unlock saveLogLock\n",log_counter,asctime (timeinfo),pthread_self());
    }
//    pthread_mutex_lock( &saveLogLock );
//
//
//
//    pthread_mutex_unlock( &saveLogLock );

}