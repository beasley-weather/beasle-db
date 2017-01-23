#include "db_consts.h"
#include "db_insert.h"


int _db_insert_user_entry(char *db_name, struct db_user_entry *entry)
{
    char *query = malloc(MAX_QUERY_LEN);
    _db_gen_insert_query_user(query, entry);

    int rc = exec_sql(db_name, query);
    free(query);

    return rc;
}

int _db_insert_weather_data_entry(char *db_name,
                                  struct db_weather_data_entry *entry)
{
    char *query = malloc(MAX_QUERY_LEN);
    _db_gen_insert_query_weather_data(query, entry);

    int rc = exec_sql(db_name, query);
    free(query);

    return rc;
}

void _db_gen_insert_query_user(char *query, struct db_user_entry *entry)
{
    // FIXME Clean this and make it less crappy
    char username[256],
         pin[256],
         name_first[256],
         name_last[256],
         home_long[256],
         home_lat[256];

    sprintf(username, "'%s'", entry->username);
    sprintf(pin, "'%s'", entry->pin);
    sprintf(name_first, "'%s'", entry->name_first);
    sprintf(name_last, "'%s'", entry->name_last);
    sprintf(home_long, "%f", entry->home_long);
    sprintf(home_lat, "%f", entry->home_lat);

    // FIXME Doing floating point comparisons (error prone?)
    sprintf(query, "INSERT INTO Users VALUES (%s, %s, %s, %s, %s, %s);",
            (entry->username == NULL) ? NULL_STRING : username,
            (entry->pin == NULL) ? NULL_STRING : pin,
            (entry->name_first == NULL) ? NULL_STRING : name_first,
            (entry->name_last == NULL) ? NULL_STRING : name_last,
            (entry->home_long == NULL_DOUBLE) ? NULL_STRING : home_long,
            (entry->home_lat == NULL_DOUBLE) ? NULL_STRING : home_lat);
}

void _db_gen_insert_query_weather_data(char *query,
                                       struct db_weather_data_entry *entry)
{
    // FIXME Clean this and make it less crappy
    char username[256],
         time[256],
         data_long[256],
         data_lat[256],
         noise[256],
         dusts[256],
         temp[256],
         humidity[256],
         wind[256];

    sprintf(username, "'%s'", entry->username);
    sprintf(time, "'%s'", entry->time);
    sprintf(data_long, "%f", entry->data_long);
    sprintf(data_lat, "%f", entry->data_lat);
    sprintf(noise, "%f", entry->noise);
    sprintf(dusts, "%f", entry->dusts);
    sprintf(temp, "%f", entry->temp);
    sprintf(humidity, "%f", entry->humidity);
    sprintf(wind, "%f", entry->wind);

    // FIXME Doing floating point comparisons (error prone?)
    sprintf(query, "INSERT INTO Weather_Data VALUES (%s, %s, %s, %s, %s, %s,"
                   " %s, %s, %s);",
            (entry->username == NULL) ? NULL_STRING : username,
            (entry->time == NULL) ? NULL_STRING : time,
            (entry->data_long == NULL_DOUBLE) ? NULL_STRING : data_long,
            (entry->data_lat == NULL_DOUBLE) ? NULL_STRING : data_lat,
            (entry->noise == NULL_DOUBLE) ? NULL_STRING : noise,
            (entry->dusts == NULL_DOUBLE) ? NULL_STRING : dusts,
            (entry->temp == NULL_DOUBLE) ? NULL_STRING : temp,
            (entry->humidity == NULL_DOUBLE) ? NULL_STRING : humidity,
            (entry->wind == NULL_DOUBLE) ? NULL_STRING : wind);
}
