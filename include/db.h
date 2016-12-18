#pragma once
#define DB_H

struct db_user_entry
{
    char *username,
           *pin,
           *name_first,
           *name_last;
    double home_long,
           home_lat;
};

struct db_weahther_data_entry
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


int db_create();
int db_insert();
void db_select();
