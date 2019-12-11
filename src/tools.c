//
// Created by avicii on 6/5/19.
//


#include "../includes/tools.h"
#include "../includes/output.h"
#include "../includes/handleMessage.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//ITOA
char itoa_buffer[20];

char* itoa(int i){

    sprintf(itoa_buffer, "%d", i);
    return &itoa_buffer;
}

// looks for the first appearnce of char c from index ,
//return the index of the first appearnce of char c.
// if c isnt found return -1
int indexof(char c,char* str,int index ){
    if(index<0)
        return -1;

    int strLength=strlen(str);
    while(index<strLength){
        if(str[index]==c)
            return index;
        index++;
    }
    return  -1;
}