#include <stdio.h>
#include <unistd.h>

#include <criterion/criterion.h>

#include "db.h"


struct db_user_entry user;
struct db_weather_data_entry weather;

char *sql;

char *test_username = "alice",
     *test_pin = "123abc",
     *test_name_first = "Alice",
     *test_name_last = "Doe",
     *test_time = "2009-11-12";

double test_home_long = 123.456,
       test_home_lat = 23.45,
       test_data_long = 32.43,
       test_data_lat = 43.2,
       test_noise = 11.22,
       test_dusts = 323.44,
       test_temp = 12.3,
       test_humidity = 98.2,
       test_wind = 44.85;


void setup_user_entry_inited() {
    sql = malloc(256);

    db_init_user_entry(&user);

    _db_gen_insert_query_user(sql, &user);
}

void setup_user_entry_mixed() {
    sql = malloc(256);

    db_init_user_entry(&user);
    user.pin = test_pin;
    user.name_last = test_name_last;
    user.home_lat = test_home_lat;

    _db_gen_insert_query_user(sql, &user);
}

void setup_user_entry_full() {
    sql = malloc(256);

    user.username = test_username;
    user.pin = test_pin;
    user.name_last = test_name_last;
    user.name_first = test_name_first;
    user.home_lat = test_home_lat;
    user.home_long = test_home_long;

    _db_gen_insert_query_user(sql, &user);
}


void setup_weather_data_entry_inited() {
    sql = malloc(256);

    db_init_weather_data_entry(&weather);

    _db_gen_insert_query_weather_data(sql, &weather);
}

void setup_weather_data_entry_mixed() {
    sql = malloc(256);

    db_init_weather_data_entry(&weather);
    weather.username = test_username;
    weather.data_long = test_data_long;
    weather.dusts = test_dusts;
    weather.temp = test_temp;

    _db_gen_insert_query_weather_data(sql, &weather);
}

void setup_weather_data_entry_full() {
    sql = malloc(256);

    weather.username = test_username;
    weather.time = test_time;
    weather.data_long = test_data_long;
    weather.data_lat = test_data_lat;
    weather.noise = test_noise;
    weather.dusts = test_dusts;
    weather.temp = test_temp;
    weather.humidity = test_humidity;
    weather.wind = test_wind;

    _db_gen_insert_query_weather_data(sql, &weather);
}


void teardown_query() {
    free(sql);
}


Test(test_db_insert, test_insert_query_gen_null_user,
     .init=setup_user_entry_inited,
     .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Users VALUES (null, null, null, null, null, null);");
}

Test(test_db_insert, test_insert_query_gen_mixed_user,
     .init=setup_user_entry_mixed,
     .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Users VALUES (null, 123abc, null, Doe, null,"
            " 23.450000);");
}

Test(test_db_insert, test_insert_query_gen_full_user,
     .init=setup_user_entry_full,
     .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Users VALUES (alice, 123abc, Alice, Doe, 123.456000,"
            " 23.450000);");
}


Test(test_db_insert, test_insert_query_gen_null_weather_data,
     .init=setup_weather_data_entry_inited, .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Weather_Data VALUES (null, null, null, null, null,"
            " null, null, null, null);");
}

Test(test_db_insert, test_insert_query_gen_mixed_weather_data,
     .init=setup_weather_data_entry_mixed, .fini=teardown_query) {
    cr_assert_str_eq(sql, "INSERT INTO Weather_Data VALUES (alice, null,"
            " 32.430000, null, null, 323.440000, 12.300000, null, null);");
}

Test(test_db_insert, test_insert_query_gen_full_weather_data,
     .init=setup_weather_data_entry_full, .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Weather_Data VALUES (alice, 2009-11-12, 32.430000,"
            " 43.200000, 11.220000, 323.440000, 12.300000, 98.200000,"
            " 44.850000);");
}
