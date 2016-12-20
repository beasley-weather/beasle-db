#pragma once
#define DB_CREATE_H

/*
 * Error return codes:
 *   -1     Failed to open database
 *   -2     Failed to execute schema
 */
int _db_create(char* db_name, char* schema_file);
