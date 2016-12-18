CC = gcc
LIB_SQLITE = -l sqlite3

TEST_BIN = bin/

TEST_STRUCTS_EXEC = $(TEST_BIN)test_structs
TEST_EXECS       = $(TEST_STRUCTS_EXEC)

TEST_STRUCTS = test_structs.c


all: test_bin
	$(CC) -o $(TEST_STRUCTS_EXEC) $(TEST_STRUCTS)

test_bin:
	mkdir -p $(TEST_BIN)

clean:
	rm -f $(TEST_EXECS)
	rmdir $(TEST_BIN)
