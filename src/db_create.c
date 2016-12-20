#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

char* readSchema(char* schema_file) {
    FILE *fp = fopen(schema_file, "r");
    int buf_len = 10;
    int buf_cur = 0;
    char *buf = malloc(buf_len);
    char c;

    if (fp == NULL || buf == NULL)
        return NULL;    // failed to open file or allocate buffer

    while ((c = fgetc(fp)) != EOF)
    {
        if (buf_cur >= buf_len-1)
        {
            buf_len += 10;
            buf = realloc(buf, buf_len);
            if (buf == NULL)
                return NULL;    // failed to allocate buffer
        }

        buf[buf_cur++] = c;
    }

    buf[buf_cur] = '\0';

    return buf;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  for(i=0; i<argc; i++)
  {
     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int _db_create(char* db_name, char* schema_file)
{
  sqlite3 *db;
  char *zErrMsg = 0;
  int  rc;
  char *sql;

  /* Open database */
  rc = sqlite3_open(db_name, &db);
  if( rc )
    return -1;

  /* Create SQL statement */
  sql = readSchema(schema_file);

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  if( rc != SQLITE_OK )
    sqlite3_free(zErrMsg);
    goto ERR;

  sqlite3_close(db);
  return 0;

  ERR:
    sqlite3_close(db);
    return -2;
}
