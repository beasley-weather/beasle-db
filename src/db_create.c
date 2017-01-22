#include "db_create.h"


int _db_create(char* db_name, char* schema_file)
{
    char *sql = NULL;
    sql = _read_schema(sql, schema_file);

    /* Execute SQL statement */
    int rc = exec_sql(db_name, sql);

    /* read_schema allocates memory */
    free(sql);

    return rc;
}

char* _read_schema(char* buf, char* schema_file)
{
    FILE *fp = fopen(schema_file, "r");
    int buf_len = 10;
    int buf_cur = 0;
    buf = realloc(buf, buf_len);
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
