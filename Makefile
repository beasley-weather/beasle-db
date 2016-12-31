CC		  := gcc
CFLAGS	  := -Wall
INC		  := -I include
LIBS	  := -l sqlite3
TEST_LIBS := -l criterion


DIRS := bin


all: $(DIRS) bin/test_schema.sql bin/test_structs bin/test_db_create

$(DIRS):
	mkdir -p $@

bin/test_schema.sql: test/test_schema.sql
	cp $< $@

bin/test_structs: test/test_structs.c src/db.c src/db_create.c
	$(CC) $(FLAGS) $(INC) $(LIBS) $(TEST_LIBS) $^ -o $@

bin/test_db_create: test/test_db_create.c src/db.c src/db_create.c
	$(CC) $(FLAGS) $(INC) $(LIBS) $(TEST_LIBS) $^ -o $@


clean_all: clean
	rm -rf bin/*

clean:
	rm -rf build*
