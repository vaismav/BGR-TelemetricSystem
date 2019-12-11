//
// Created by avicii on 26/08/2019.
//

#ifndef CSERVER_DBTOOLS_H
#define CSERVER_DBTOOLS_H
#include <bson/bson.h>
#include <mongoc.h>

char* db_name;

mongoc_database_t *mongocDatabase;

mongoc_uri_t *uri;

mongoc_client_t *mongocClient;

int init_db (int running_version);
int insertNewBsonDocument(char* collectionName, bson_t* bson)

#endif //CSERVER_DBTOOLS_H
