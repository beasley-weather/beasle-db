#include "db_create.h"
#include "db_insert.h"
#include "db_select.h"

int db_create(char* db_name, char* schema_file)
{
    int rc = _db_create(db_name, schema_file);

    return rc;
}

int db_insert()
{

}

void db_select()
{

}
