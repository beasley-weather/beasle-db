#include <assert.h>
#include <stdio.h>
#include "../include/db.h"

struct db_user_entry a, b, c;

char *a_username = "alex",
     *b_username = "bob",
     *c_username = "cindy",

     *a_pin = "123",
     *b_pin = "23452",
     *c_pin = "6564";


void test_setup()
{
    a.username = a_username;
    a.pin = a_pin;

    b.username = b_username;
    b.pin = b_pin;

    c.username = c_username;
    c.pin = c_pin;
}

int test()
{
    assert(a.username == a_username);
    assert(a.pin == a_pin);
    assert(b.username == b_username);
    assert(b.pin == b_pin);
    assert(c.username == c_username);
    assert(c.pin == c_pin);
    return 0;
}

int main()
{
    test_setup();
    if (!test())
    {
        printf("All %s tests passed.\n", "struct");
        return 0;
    }
}
