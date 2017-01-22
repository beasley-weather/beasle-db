#pragma once
#define DB_UTILS_H

#include <sqlite3.h>
#include <stdio.h>


int exec_sql(char *db_name, char *sql);

int _callback(void *NotUsed, int argc, char **argv, char **azColName);
