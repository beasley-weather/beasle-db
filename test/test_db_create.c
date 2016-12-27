#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include "db.h"


char *test_db = "test.db";
char *test_schema = "test_schema.sql";

FILE *fp;


void test_cleanup();


/*
 * Setup test
 * - Check if test_db file exists
 *  `- delete file if exists
 * - Check access to test_schema
 */
int test_setup() {
    if (access(test_db, F_OK) != -1)
        test_cleanup();

    if (access(test_schema, R_OK) == -1) {
        printf("Unable to read schema file, %s\n", test_schema);
        return -1;
    }

    return 0;
}


void test_cleanup() {
    unlink(test_db);
}


int test() {
    assert(db_create(test_db, test_schema) == 0);
    return 0;
}


int main(int argc, char **argv) {
    if (test_setup())
        return -1;

    int rc = test();

    /*
     * Preserve test_db file after running test
     * Use -p flag
     */
    if (!(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'p'))
        test_cleanup();

    if (!rc) {
        printf("All %s tests passed.\n", "db_create");
        return 0;
    } else {
        printf("%s returned: %i\n", "db_create", rc);
    }
}
