//
// Created by avicii on 5/5/19.
//

#ifndef CSERVER_OUTPUT_H
#define CSERVER_OUTPUT_H

#include<pthread.h>

void init_output();

void saveShortLog(char* str);

void saveLog(char* str1,char* str2,char* str3,char* str4, char* str5);



#endif //CSERVER_OUTPUT_H
