#pragma once
#define DB_INSERT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

/*
 * hardcoded, should a different value be needed, it maybe useful to change
 * code to allow dynamic reallocation
 */
#Define VALUES_LEN 256

void trim_trailing_comma(char *string);


char* generate_insert_user_labels(struct db_user_entry *entry);

char* generate_insert_user_values(struct db_user_entry *entry);


int _db_insert_user_entry(char* db_name, struct db_user_entry *entry);


int _db_insert_weather_data_entry(char* db_name,
                                  struct db_weather_data_entry *entry);
