#pragma once
#define DB_H

#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NULL_INT -987654321
#define NULL_DOUBLE -987654321.0
#define NULL_STRING "null"

/*
 * FIXME
 * hardcoded, should a different value be needed, it maybe useful to change
 * code to allow dynamic reallocation
 */
#define MAX_QUERY_LEN 256


struct db_user_entry {
    char *username,
           *pin,
           *name_first,
           *name_last;
    double home_long,
           home_lat;
};

struct db_weather_data_entry {
    char *username,
           *time;
    double data_long,
           data_lat,
           noise,
           dusts,
           temp,
           humidity,
           wind;
};


/*
 * Return codes:
 *    0     Success
 *   -1     Failed to open database
 *   -2     Failed to execute schema
 */
int db_create(char *db_name, char *schema_file);

void db_init_user_entry(struct db_user_entry *entry);

void db_init_weather_data_entry(struct db_weather_data_entry *entry);


/* DB CREATE ----------------------------------------------------------------*/

int _db_create(char *db_name, char *schema_file);

char* _read_schema(char* buf, char* schema_file);


/* DB INSERT ----------------------------------------------------------------*/

int db_insert_user_entry(char *db_name, struct db_user_entry *entry);

int db_insert_weather_data_entry(char* db_name,
                                   struct db_weather_data_entry *entry);

void _db_gen_insert_query_user(char *query,
                               struct db_user_entry *entry);

void _db_gen_insert_query_weather_data(char *query,
                                       struct db_weather_data_entry *entry);


/* DB SELECT ----------------------------------------------------------------*/

char* db_select(char* db_name, char* table, char* attributes);


/* SQL UTILS ----------------------------------------------------------------*/

int exec_sql(char *db_name, char *sql);

int _callback(void *NotUsed, int argc, char **argv, char **azColName);
