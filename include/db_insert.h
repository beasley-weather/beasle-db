#pragma once
#define DB_INSERT_H

#include "db_data.h"
#include "db_utils.h"

#include "stdio.h"
#include "stdlib.h"


int _db_insert_user_entry(char *db_name, struct db_user_entry *entry);

int _db_insert_weather_data_entry(char* db_name,
                                   struct db_weather_data_entry *entry);

void _db_gen_insert_query_user(char *query,
                               struct db_user_entry *entry);

void _db_gen_insert_query_weather_data(char *query,
                                       struct db_weather_data_entry *entry);
