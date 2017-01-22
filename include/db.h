#pragma once
#define DB_H

#include "db_consts.h"
#include "db_create.h"
#include "db_insert.h"

#include "stdlib.h"


/*
 * Return codes:
 *    0     Success
 *   -1     Failed to open database
 *   -2     Failed to execute schema
 */
int db_create(char *db_name, char *schema_file);

int db_insert_user_entry(char *db_name, struct db_user_entry *entry);

int db_insert_weather_data_entry(char* db_name,
                                   struct db_weather_data_entry *entry);

char* db_select(char* db_name, char* table, char* attributes);
