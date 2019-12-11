//
// Created by avicii on 26/08/2019.
//https://idea.popcount.org/2012-09-11-concurrent-queue-in-c/

#ifndef CSERVER_SEMIBLOCKINGQUEUE_H
#define CSERVER_SEMIBLOCKINGQUEUE_H

#include "../includes/handleMessage.h"
#include <pthread.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <bson/bson-types.h>

struct Queue_Head{
    char* msg;
    bson_t* bson;
    dataNode* bsonData;
    struct Queue_Head* next;
}Queue_Head;

struct Queue_Root{
    struct Queue_Head* inQueue;
    struct Queue_Head* outQueue;
    pthread_mutex_t lock;
};

struct Queue_Root* initSemiBlockingQueue();

struct Queue_Head* createMsgNode(char* msg);

struct Queue_Head *createDataNode(bson_t *data, struct bsonData *newBsonData);

void enqueue(struct Queue_Root* root,struct Queue_Head* new);

struct Queue_Head* dequeue(struct Queue_Root* root)

#endif //CSERVER_SEMIBLOCKINGQUEUE_H
