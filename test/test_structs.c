#include <stdio.h>

#include <criterion/criterion.h>

#include "db.h"


struct db_user_entry user, user_inited;
struct db_weather_data_entry weather, weather_inited;

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


void setup_user_struct_assigned() {
    user.username = test_username;
    user.pin = test_pin;
    user.name_first = test_name_first;
    user.name_last = test_name_last;
    user.home_long = test_home_long;
    user.home_lat = test_home_lat;
}


void setup_user_struct_init() {
    db_init_user_entry(&user_inited);
}


void setup_weather_data_struct_assigned() {
    weather.username = test_username;
    weather.time = test_time;
    weather.data_long = test_data_long;
    weather.data_lat = test_data_lat;
    weather.noise = test_noise;
    weather.dusts = test_dusts;
    weather.temp = test_temp;
    weather.humidity = test_humidity;
    weather.wind = test_wind;
}


void setup_weather_data_struct_inited() {
    db_init_weather_data_entry(&weather_inited);
}


Test(test_structs, test_user_struct_assigned, .init=setup_user_struct_assigned) {
    cr_expect_str_eq(user.username, test_username,
            "Username should be assigned to struct.\n%s == %s",
            user.username, test_username);

    cr_expect_str_eq(user.pin, test_pin,
            "Pin should be assigned to struct.\n%s == %s",
            user.pin, test_pin);

    cr_expect_str_eq(user.name_first, test_name_first,
            "First name should be assigned to struct.\n%s == %s",
            user.name_first, test_name_first);

    cr_expect_str_eq(user.name_last, test_name_last,
            "First name should be assigned to struct.\n%s == %s",
            user.name_last, test_name_last);

    cr_expect_float_eq(user.home_long, test_home_long, 1e-5,
            "Home long should be assigned to struct.");

    cr_expect_float_eq(user.home_lat, test_home_lat, 1e-5,
            "Home lat should be assigned to struct.");
}


Test(test_structs, test_user_struct_init, .init=setup_user_struct_init) {
    cr_expect_null(user_inited.username, "Username should be NULL.");

    cr_expect_null(user_inited.pin, "Pin should be NULL.");

    cr_expect_null(user_inited.name_first, "First name should be NULL.");

    cr_expect_null(user_inited.name_last, "First name should be NULL.");

    cr_expect_float_eq(user_inited.home_long, NULL_DOUBLE, 1e-5,
            "Home long should be NULL_DOUBLE.");

    cr_expect_float_eq(user_inited.home_lat, NULL_DOUBLE, 1e-5,
            "Home lat should be NULL_DOUBLE.");
}


Test(test_structs, test_weather_data_struct_assigned, .init=setup_weather_data_struct_assigned) {
    cr_expect_str_eq(weather.username, test_username,
            "Username should be assigned to struct.");

    cr_expect_str_eq(weather.time, test_time,
            "Pin should be assigned to struct.");

    cr_expect_float_eq(weather.data_long, test_data_long, 1e-5,
            "Data long should be assigned to struct.");

    cr_expect_float_eq(weather.data_lat, test_data_lat, 1e-5,
            "Data lat should be assigned to struct.");

    cr_expect_float_eq(weather.noise, test_noise, 1e-5,
            "Noise should be assigned to struct.");

    cr_expect_float_eq(weather.dusts, test_dusts, 1e-5,
            "Dust should be assigned to struct.");

    cr_expect_float_eq(weather.temp, test_temp, 1e-5,
            "Temp should be assigned to struct.");

    cr_expect_float_eq(weather.humidity, test_humidity, 1e-5,
            "Humidity should be assigned to struct.");

    cr_expect_float_eq(weather.wind, test_wind, 1e-5,
            "Wind should be assigned to struct.");
}


Test(test_structs, test_weather_data_struct_init, .init=setup_weather_data_struct_inited) {
    cr_expect_null(weather_inited.username, "Username should be NULL.");

    cr_expect_null(weather_inited.time, "Time should be NULL.");

    cr_expect_float_eq(weather_inited.data_long, NULL_DOUBLE, 1e-5,
            "Data long should be NULL_DOUBLE.");

    cr_expect_float_eq(weather_inited.data_lat, NULL_DOUBLE, 1e-5,
            "Data lat should be NULL_DOUBLE.");

    cr_expect_float_eq(weather_inited.noise, NULL_DOUBLE, 1e-5,
            "Noise should be NULL_DOUBLE.");

    cr_expect_float_eq(weather_inited.dusts, NULL_DOUBLE, 1e-5,
            "Dust should be NULL_DOUBLE.");

    cr_expect_float_eq(weather_inited.temp, NULL_DOUBLE, 1e-5,
            "Temp should be NULL_DOUBLE.");

    cr_expect_float_eq(weather_inited.humidity, NULL_DOUBLE, 1e-5,
            "Humidity should be NULL_DOUBLE.");

    cr_expect_float_eq(weather_inited.wind, NULL_DOUBLE, 1e-5,
            "Wind should be NULL_DOUBLE.");
}
