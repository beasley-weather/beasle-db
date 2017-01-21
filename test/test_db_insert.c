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


void setup_user_entry() {
    sql = malloc(256);

    db_init_user_entry(&user);

    _db_gen_insert_query_user(sql, &user);
}

void setup_weather_data_entry() {
    sql = malloc(256);

    db_init_weather_data_entry(&weather);

    _db_gen_insert_query_weather_data(sql, &weather);
}

void teardown_query() {
    free(sql);
}

Test(test_db_insert, test_user_insert_query, .init=setup_user_entry,
     .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Users VALUES (null, null, null, null, null, null);");
}

Test(test_db_insert, test_weather_data_insert_query,
     .init=setup_weather_data_entry, .fini=teardown_query) {
    cr_assert_str_eq(sql,
            "INSERT INTO Weather_Data VALUES (null, null, null, null, null,"
            " null, null, null, null);");
}
