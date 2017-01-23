#pragma once
#define DB_CREATE_H


#include "stdio.h"
#include "stdlib.h"

#include "db_utils.h"


int _db_create(char *db_name, char *schema_file);

char* _read_schema(char* buf, char* schema_file);
