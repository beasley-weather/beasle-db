CC		  := gcc
CFLAGS	  := -Wall -g
INC		  := -I include
LIBS	  := -l sqlite3
TEST_LIBS := -l criterion


all: bin bin/test_schema.sql bin/test_structs bin/test_db_create bin/test_db_insert

bin:
	mkdir -p bin

bin/test_schema.sql: test/test_schema.sql
	cp $^ $@

bin/test_structs: test/test_structs.c src/db_data.c
	$(CC) $(CFLAGS) $(INC) $(LIBS) $(TEST_LIBS) $^ -o $@

bin/test_db_create: test/test_db_create.c src/db_create.c src/db_utils.c
	$(CC) $(CFLAGS) $(INC) $(LIBS) $(TEST_LIBS) $^ -o $@

bin/test_db_insert: test/test_db_insert.c src/db_data.c src/db_create.c src/db_insert.c src/db_utils.c
	$(CC) $(CFLAGS) $(INC) $(LIBS) $(TEST_LIBS) $^ -o $@

clean:
	rm -rf bin/*
