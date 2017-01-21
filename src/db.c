#include "db.h"


int db_create(char *db_name, char *schema_file) {
    int rc = _db_create(db_name, schema_file);

    return rc;
}


void db_init_user_entry(struct db_user_entry *entry) {
    entry->username = NULL;
    entry->pin = NULL;
    entry->name_first = NULL;
    entry->name_last = NULL;
    entry->home_long = NULL_DOUBLE;
    entry->home_lat = NULL_DOUBLE;
}


void db_init_weather_data_entry(struct db_weather_data_entry *entry) {
    entry->username = NULL;
    entry->time = NULL;
    entry->data_long = NULL_INT;
    entry->data_lat = NULL_INT;
    entry->noise = NULL_INT;
    entry->dusts = NULL_INT;
    entry->temp = NULL_INT;
    entry->humidity = NULL_INT;
    entry->wind = NULL_INT;
}


/*
int db_insert_user_entry(char* db_name, db_user_entry entry[]) {
    // generate sql queries
    // execute queries
        // failure, return error code
    return 0;
}
*/


/*
int db_insert_weather_data_entry(char* db_name, db_weather_data_entry entry[]) {
    // generate sql queries
    // execute queries
        // failure, return error code
    return 0;
}
*/


/*
char* db_select(char* db_name, char* table, char* attributes) {
    char* result;
    // generate sql query
    // execute query
    return result;
}
*/










/* DB CREATE ----------------------------------------------------------------*/

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
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

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


/* DB INSERT ----------------------------------------------------------------*/

void db_insert_user_entry(char *db_name, struct db_user_entry *entry)
{
    char *query = malloc(MAX_QUERY_LEN);
    _db_gen_insert_query_user(query, entry);
}

void db_insert_weather_data_entry(char *db_name,
                                  struct db_weather_data_entry *entry)
{
    char *query = malloc(MAX_QUERY_LEN);
    _db_gen_insert_query_weather_data(query, entry);
}

void _db_gen_insert_query_user(char *query, struct db_user_entry *entry)
{
    /* how many digits is a double? */
    char home_long[64],
         home_lat[64];

    sprintf(home_long, "%f", entry->home_long);
    sprintf(home_lat, "%f", entry->home_lat);

    sprintf(query, "INSERT INTO Users VALUES (%s, %s, %s, %s, %s, %s);",
            (entry->username == NULL) ? NULL_STRING : entry->username,
            (entry->pin == NULL) ? NULL_STRING : entry->pin,
            (entry->name_first == NULL) ? NULL_STRING : entry->name_first,
            (entry->name_last == NULL) ? NULL_STRING : entry->name_last,
            (entry->home_long == NULL_DOUBLE) ? NULL_STRING : home_long,
            (entry->home_lat == NULL_DOUBLE) ? NULL_STRING : home_lat);
}

void _db_gen_insert_query_weather_data(char *query,
                                       struct db_weather_data_entry *entry)
{
    char data_long[64],
         data_lat[64],
         noise[64],
         dusts[64],
         temp[64],
         humidity[64],
         wind[64];

    sprintf(data_long, "%f", entry->data_long);
    sprintf(data_lat, "%f", entry->data_lat);
    sprintf(noise, "%f", entry->noise);
    sprintf(dusts, "%f", entry->dusts);
    sprintf(temp, "%f", entry->temp);
    sprintf(humidity, "%f", entry->humidity);
    sprintf(wind, "%f", entry->wind);

    sprintf(query, "INSERT INTO Weather_Data VALUES (%s, %s, %s, %s, %s, %s,"
                   " %s, %s, %s);",
            (entry->username == NULL) ? NULL_STRING : entry->username,
            (entry->time == NULL) ? NULL_STRING : entry->time,
            (entry->data_long == NULL_DOUBLE) ? NULL_STRING : data_long,
            (entry->data_lat == NULL_DOUBLE) ? NULL_STRING : data_lat,
            (entry->noise == NULL_DOUBLE) ? NULL_STRING : noise,
            (entry->dusts == NULL_DOUBLE) ? NULL_STRING : dusts,
            (entry->temp == NULL_DOUBLE) ? NULL_STRING : temp,
            (entry->humidity == NULL_DOUBLE) ? NULL_STRING : humidity,
            (entry->wind == NULL_DOUBLE) ? NULL_STRING : wind);
}
