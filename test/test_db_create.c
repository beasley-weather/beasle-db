#include <stdio.h>
#include <unistd.h>

#include <criterion/criterion.h>

#include "db.h"


char *test_db = "test.db",
     *test_schema = "test_schema.sql";

FILE *fp;


void remove_db();


void setup_db_create() {
    if (access(test_db, F_OK) != -1) {
        cr_assert_fail("Database %s, already exists.", test_db);
    }

    if (access(test_schema, R_OK) == -1) {
        cr_assert_fail("Unable to read schema file, %s.", test_schema);
    }
}


void teardown_db_create() {
    remove_db();
}


Test(test_db_create, test_db_create, .init=setup_db_create,
        .fini=teardown_db_create) {
    int rc = db_create(test_db, test_schema);
    cr_assert(rc == 0);
}


void remove_db() {
    unlink(test_db);
}
