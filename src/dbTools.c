//
// Created by avicii on 26/08/2019.
//
#include "../includes/dbTools.h"
#include "../includes/tools.h"
#include "../includes/output.h"
#include <bson/bson.h>
#include <mongoc.h>
#include <stdio.h>



char *generate_db_name(int version) {
    return "test_db";
}

void bsonErrorMsgLog(bson_error_t* error,char* callingFunc){
    saveLog("Error accurred in function ",callingFunc," : ",*error->message,"");
}


int init_db (int running_version){
    const char *uri_string = "mongodb://localhost:27017";
    bson_error_t error;

    db_name=generate_db_name(running_version);

    /*
     * Required to initialize libmongoc's internals
     */
    mongoc_init ();

    /*
     * Safely create a MongoDB URI object from the given string
     */
    uri = mongoc_uri_new_with_error (uri_string, &error);
    if (!uri) {
        fprintf (stderr,
                 "failed to parse URI: %s\n"
                 "error message:       %s\n",
                 uri_string,
                 error.message);
        return EXIT_FAILURE;
    }

    /*
     * Create a new client instance
     */
    mongocClient = mongoc_client_new_from_uri (uri);
    if (!mongocClient) {
        return EXIT_FAILURE;
    }

    /*
     * Register the application name so we can track it in the profile logs
     * on the server. This can also be done from the URI (see other examples).
     */
    mongoc_client_set_appname (mongocClient, "bgr_server");

    /*
     * Get a handle on the database "db_name" and collection "coll_name"
     */
    mongocDatabase = mongoc_client_get_database (mongocClient, db_name);

    return EXIT_SUCCESS;

}

int insertNewBsonDocument(char* collectionName, bson_t* bson){
    mongoc_collection_t* collection=mongoc_client_get_collection(mongocClient,db_name,collectionName);
    bson_error_t error;
    if(!mongoc_collection_insert_one(collection,bson,NULL,NULL,&error)){
        bsonErrorMsgLog(&error,"insertNewBsonDocument");
        return -1;
    }
    return 0;
}


int close_db(){
    mongoc_database_destroy (mongocDatabase);
    mongoc_uri_destroy (uri);
    mongoc_client_destroy (mongocClient);
    mongoc_cleanup ();

    return EXIT_SUCCESS;
}

