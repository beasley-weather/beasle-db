#include "db_create.h"
#include "db_insert.h"
#include "db_select.h"

int db_create(char* db_name, char* schema_file)
{
    int rc = _db_create(db_name, schema_file);

    return rc;
}

int db_insert_user_entry(char* db_name, struct db_user_entry[])
{
    // generate sql queries
    // execute queries
    return 0;
}

int db_insert_weather_data_entry(char* db_name, struct db_weather_data_entry[])
{
    // generate sql queries
    // execute queries
    return 0;
}

char* db_select(char* db_name, char* table, char* attributes)
{
    char* result;
    // generate sql query
    // execute query
    return result;
}
