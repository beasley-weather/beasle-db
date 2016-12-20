CC = gcc
LIB_SQLITE = -l sqlite3
INCLUDE = -I../src/_include

TEST_BIN = bin/

TEST_STRUCTS_EXEC = $(TEST_BIN)test_structs
TEST_DB_CREATE_EXEC = $(TEST_BIN)test_db_create
TEST_EXECS       = $(TEST_STRUCTS_EXEC) $(TEST_DB_CREATE_EXEC)

TEST_STRUCTS = test_structs.c
TEST_DB_CREATE = test_db_create.c

TEST_DB_CREATE_DEPS = ../src/db.c ../src/db_create.c


all: test_bin test_structs test_db_create

test_bin:
	mkdir -p $(TEST_BIN)

test_structs:
	$(CC) -o $(TEST_STRUCTS_EXEC) $(TEST_STRUCTS)

test_db_create:
	$(CC) $(INCLUDE) -o $(TEST_DB_CREATE_EXEC) $(TEST_DB_CREATE) $(TEST_DB_CREATE_DEPS)

clean:
	rm -f $(TEST_EXECS)
	rmdir $(TEST_BIN)
