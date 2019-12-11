//
// Created by avicii on 5/5/19.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/handleMessage.h"
#include "../includes/output.h"
#include "../includes/tools.h"


const char* JSON_FIELDS[]={"device","bson"};



//const char *JSON_STRING ="{\"device\": \"Jack\", \"data\": 27}";
//{"device": "Jack", "data":27}


int getFieldValue(char* message,char** dest,int field_num,int dataType,int i){
    int end_i;
    int data_length;
    char* strPtr;
    char* field_string;
    char* field_namePtr;
    switch (field_num){
        case 0: field_string="first";
            break;
        case 1: field_string="second";
            break;
    }
    i=indexof('\"',message,i);
    if(i==-1){
        saveLog("ERROR parsing the ",field_string," field. couldnt find first \" ","",";\n");
        return -1;
    }

    i++;  //advancing the index to the first letter of the first field

    strPtr = &message[i];
    field_namePtr=JSON_FIELDS[field_num];

    //checking the first field name is valid
    if(strncmp(strPtr,field_namePtr,(int)strlen(field_namePtr))!=0){ //if first field isnt equal
        saveLog("ERROR parsing the ",field_string," field. expect: ",JSON_FIELDS[field_num],";\n");
        return -1;
    }

    // look for the fields seperator
    i=indexof(':',message,i);
    if(i==-1){
        saveLog("ERROR parsing the ",field_string," field. couldnt find seperator : ","",";\n");
        return -1;
    }

    // look for first field value
    switch (dataType) {
        case STRING:
            i = indexof('"', message, i);
            if (i == -1) {
                saveLog("ERROR parsing the ",field_string," field. couldnt find first field bson ", "", ";\n");
                return -1;
            }

            i++;  //advancing the index to the first letter of the first field
            strPtr = &message[i]; // get the address of the begining of the bson string

            // look for the end of first field value
            end_i = indexof('"', message, i);
            if (end_i == -1) {
                saveLog("ERROR parsing the ",field_string," field. couldnt find seperator : ", "", ";\n");
                return -1;
            }
            data_length = end_i - i;
            char* output=malloc((data_length+1)*sizeof(char));
            int j=0;
            while (j<data_length){
                output[j]=message[i+j];
                j++;
            }
            output[data_length]=0;
            *dest=output;
            saveLog("Parsed ",field_string," field bson : ", *dest, ";\n");
            return i;
        case INT:
            //find the first number
            while( message[i] != '\0' && message[i]<'0' || '9' < message[i]  )
                i++;
            strPtr=&message[i];                                                  //strPtr pointing to the start of the bson
            data_length=0;
            while( message[i] != '\0' && message[i]>='0' && message[i]<='9' ){
                data_length++;
                i++;
            }
            *dest=malloc(sizeof(char)*data_length);
            memcpy(*dest, strPtr, data_length);
            saveLog("Parsed bson of ",field_string," field  : ", *dest, ";\n");
            return i;
    }
    return -1;
}

/**
 * receive a string of JSON structure and parsing it to a bsonData struct
 * this method expect to recive a JSON with 2 fields
 * wheres the first is "device" with string value
 * and the 2nd is "value" with string representing numeral value.
 * @param message
 * @return bsonData structure contain the sending device and the value.
 */
struct bsonData* parseMsg(char* message) {
    int i =0;
    int data;
    char* device="";
    char* data_string="";
    saveLog("Input Message: ",message,";\n","","");

    i=getFieldValue(message,&device,0,STRING,0);
    if(i==-1)
        return NULL;

    //look for the fields seperator
    i=indexof(',',message,i);
    if(i==-1){
        saveLog("ERROR parsing the second field. couldnt find seperator : , ",";\n","","","");
        return NULL;
    }

    i=getFieldValue(message,&data_string,1,INT,i);
    if(i==-1)
        return NULL;

    data = atoi(data_string);
    struct bsonData* output=malloc(sizeof(struct bsonData));
    output->datat_type=INT;
    output->device=device;
    output->value=data;
    return output;
}



void appendMessage(struct bsonData** list, struct bsonData* msg){
    printf("Parsed node: msg->device: %s \t|msg->value: %d \n",msg->device,msg->value);
    if(list==NULL){

    }
}


/**
 * this is the main function of the thread which
 * process the messages in incomingMessagesQueue
 *
 * @pre condition to insert new node to the data queue
 * is the creation of a valid bson structure.
 * @param initArg
 */
void handleMessageQueue(void* initArg){
    saveLog("handle msg List is running on thread [",itoa(pthread_self()),"]","","");
    while(1) {
        struct Queue_Head *next = dequeue(incomingMessagesQueue);
        if (next) {    //if next is not NULL
            bson_t *new_bson = bson_new_from_json ((const uint8_t *)next->msg, -1, NULL);
            struct bsonData* newBsonData=parseMsg(next->msg);       //bsonData is compute to have easy access to the json info.
            if (new_bson) {    //if new is not NULL
                enqueue(dataNodesQueue, createDataNode(new_bson, newBsonData));
            }
            free(next);
        }
    }
}

/**
 * this is the main function of the thread which
 * process the data in the dataNodesQueue.
 *
 * @pre condition to insert data into a collection
 * is the exist of valid bson in Queue_Head structure.
 * by definition, @handleMessageQueue adding nodes to dataNodesQueue
 * only upon genareting valid bson so no need to check if bson is valid.
 * @param initArg
 */
void handleDataQueue(void* initArg){
    while(1){
        struct Queue_Head* next=dequeue(dataNodesQueue);
        if(next ){
            if(next->bsonData){
                insertNewBsonDocument(next->bson,next->bsonData->device);
                free(next->bsonData);
                bson_destroy(next->bson);
            }
            else{
                insertNewBsonDocument(next->bson,"");
                bson_destroy(next->bson);
            }


        }

    }
}
