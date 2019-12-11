//
// Created by avicii on 26/08/2019.
//
#include "../includes/semiBlockingQueue.h"

struct Queue_Root* initSemiBlockingQueue(){
    struct Queue_Root* output=malloc(sizeof(struct Queue_Root));
    output->outQueue=NULL;
    output->inQueue=NULL;
    return output;
}


struct Queue_Head* createMsgNode(char* msg){
    struct Queue_Head* output=malloc(sizeof(struct Queue_Head));
    output->msg=msg;
    return output;
}

struct Queue_Head *createDataNode(bson_t* newBson, struct bsonData* newBsonData) {
    struct Queue_Head* output=malloc(sizeof(struct Queue_Head));
    output->bson=newBson;
    output->bsonData->device=newBsonData->device;
    output->bsonData->value=newBsonData->value;
    output->bsonData->datat_type=newBsonData->datat_type;
    return output;
}

void enqueue(struct Queue_Root* root,struct Queue_Head* new){
    while(1){
        struct Queue_Head* oldHead=root->inQueue;
        new->next=oldHead;
        if(atomic_compare_exchange_strong(&root->inQueue,oldHead,new))
            break;
    }
}

void refillOutQueue(struct Queue_Root* root, struct Queue_Head* inQueue){
    struct Queue_Head* tempHead;
    while(inQueue){
        tempHead=inQueue->next;
        inQueue->next=root->outQueue;
        inQueue=tempHead;
    }

}

/**
 * dequeu one head from the queue
 * @param root
 * @return
 */
struct Queue_Head* dequeue(struct Queue_Root* root){
    pthread_mutex_lock(&root->lock);
    if(!root->outQueue){
        while(1){
            struct Queue_Head* inQueue=root->inQueue;
            if(!inQueue)                              //if inQueue is empty
                return NULL;
            if(atomic_compare_exchange_strong(&root->inQueue,inQueue,NULL)){
                refillOutQueue(root,inQueue);
                break;
            }
        }
    }
    struct Queue_Head* output=root->outQueue;
    if(output){                                     //if output is not NULL
        root->outQueue=output->next;
        output->next=NULL;
    }
    return output;
}