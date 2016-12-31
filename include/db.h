#pragma once
#define DB_H

#include "db_create.h"


#define NULL_INT -987654321
#define NULL_DOUBLE -987654321.0


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


//int db_insert_user_entry(char* db_name, db_user_entry entry[]);


//int db_insert_weather_data_entry(char* db_name, db_weather_data_entry entry[]);


//char* db_select(char* db_name, char* table, char* attributes)
