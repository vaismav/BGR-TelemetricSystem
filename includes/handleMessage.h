//
// Created by avicii on 5/8/19.
//

#ifndef CSERVER_HANDLEMESSAGE_H
#define CSERVER_HANDLEMESSAGE_H


#include "semiBlockingQueue.h"
#include "../includes/dbTools.h"
#include <bson/bson.h>

#define STRING 0
#define INT 1
#define NUMBER 2


typedef struct bsonData {
    char*   device;
    int   datat_type;
    int        value;
} dataNode;



struct Queue_Root* incomingMessagesQueue=NULL;
struct Queue_Root* dataNodesQueue=NULL;


void throwError(char *msq);

//add msg to the end of list
void appendMessage(bsonData** list, bsonData* msg);

void handleMessageQueue(void* initArg);

void handleDataQueue(void* initArg);

int getFieldValue(char* message,char** dest,int field_num,int dataType,int index);

bsonData* parseMsg(char* message) ;

#endif //CSERVER_HANDLEMESSAGE_H
