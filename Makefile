CC		  := gcc
CFLAGS	  := -Wall
INC		  := -I include
LIBS	  := -l sqlite3
TEST_LIBS := -l criterion


DIRS := build bin


all: $(DIRS) bin/test_structs

$(DIRS):
	mkdir -p $@

bin/test_structs: test/test_structs.c src/db.c src/db_create.c
	$(CC) $(FLAGS) $(INC) $(LIBS) $(TEST_LIBS) $^ -o $@


clean_all: clean
	rm -rf bin/*

clean:
	rm -rf build*
