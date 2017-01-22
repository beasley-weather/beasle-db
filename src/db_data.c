#include "stdio.h"

#include "db_consts.h"
#include "db_data.h"


void db_init_user_entry(struct db_user_entry *entry)
{
    entry->username = NULL;
    entry->pin = NULL;
    entry->name_first = NULL;
    entry->name_last = NULL;
    entry->home_long = NULL_DOUBLE;
    entry->home_lat = NULL_DOUBLE;
}

void db_init_weather_data_entry(struct db_weather_data_entry *entry)
{
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
