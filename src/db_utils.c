#include "db.h"


int exec_sql(char *db_name, char *sql)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int  rc;

    /* Open database */
    rc = sqlite3_open(db_name, &db);
    if( rc )
        return -1;

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, _callback, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        sqlite3_free(zErrMsg);
        goto ERR;
    }

    sqlite3_close(db);
    return 0;

    ERR:
        sqlite3_close(db);
        return -2;
}

int _callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i=0; i<argc; i++)
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

    printf("\n");
    return 0;
}
