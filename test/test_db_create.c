#include <assert.h>
#include <stdio.h>
#include "../include/db.h"

char *test_db = "test.db";
char *test_schema = "test.schema";

FILE *fp;

int test_setup()
{
    fp = fopen(test_db, "r");
    if (fp == NULL)
        return -1;

    return 0;
}

int test_cleanup()
{
    // delete test_db;
}

int test()
{
    assert(db_create(test_db, test_schema) == 0);
    return 0;
}

int main()
{
    if (!test_setup())
    {
        printf("Test setup failed");
        return -1;
    }

    int rc = test();

    test_cleanup();

    if (!rc)
    {
        printf("All %s tests passed.\n", "db_create");
        return 0;
    }
}
