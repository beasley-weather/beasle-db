#include "db.h"


int db_create(char *db_name, char *schema_file) {
    int rc = _db_create(db_name, schema_file);

    return rc;
}


void db_init_user_entry(struct db_user_entry *entry) {
    entry->username = NULL;
    entry->pin = NULL;
    entry->name_first = NULL;
    entry->name_last = NULL;
    entry->home_long = NULL_DOUBLE;
    entry->home_lat = NULL_DOUBLE;
}


void db_init_weather_data_entry(struct db_weather_data_entry *entry) {
    entry->username = NULL;
    entry->time = NULL;
    entry->data_long = NULL_INT;
    entry->data_lat = NULL_INT;
    entry->noise = NULL_INT;
    entry->dusts = NULL_INT;
    entry->temp = NULL_INT;
    entry->humidity = NULL_INT;
    entry->wind = NULL_INT;
}


/*
int db_insert_user_entry(char* db_name, db_user_entry entry[]) {
    // generate sql queries
    // execute queries
        // failure, return error code
    return 0;
}
*/


/*
int db_insert_weather_data_entry(char* db_name, db_weather_data_entry entry[]) {
    // generate sql queries
    // execute queries
        // failure, return error code
    return 0;
}
*/


/*
char* db_select(char* db_name, char* table, char* attributes) {
    char* result;
    // generate sql query
    // execute query
    return result;
}
*/
