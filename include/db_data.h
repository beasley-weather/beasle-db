#pragma once
#define DB_DATA_H


struct db_user_entry
{
    char *username,
         *pin,
         *name_first,
         *name_last;
    double home_long,
           home_lat;
};

struct db_weather_data_entry
{
    char *username,
         *time;
    double data_long,
           data_lat,
           noise,
           dusts,
           temp,
           humidity,
           wind;
};


void db_init_user_entry(struct db_user_entry *entry);

void db_init_weather_data_entry(struct db_weather_data_entry *entry);
