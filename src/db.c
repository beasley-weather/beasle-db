#include "db.h"


int db_create(char *db_name, char *schema_file)
{
    int rc = _db_create(db_name, schema_file);

    return rc;
}

int db_insert_user_entry(char *db_name, struct db_user_entry *entry)
{
    int rc = _db_insert(db_name, entry);

    return rc;
}

int db_insert_weather_data_entry(char *db_name,
                                  struct db_weather_data_entry *entry)
{
    int rc = _db_insert(db_name, entry);

    return rc;
}

char* db_select(char* db_name, char* table, char* attributes)
{
    return NULL;
}
