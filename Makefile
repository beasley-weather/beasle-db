CC						:= gcc
CFLAGS					:= -Wall
INC						:= -I include
LIBS					:= -l sqlite3


BIN						:= bin/
BUILD					:= build/
DIRS					:= $(BIN) $(BUILD)
SRC						:= src/
TEST					:= test/

TEST_SCHEMA				:= $(TEST)test_schema.sql

TEST_STRUCTS_SRC		:= $(TEST)test_structs.c
TEST_STRUCTS			:= $(BIN)test_structs

TEST_DB_CREATE_SRC		:= $(TEST)test_db_create.c
TEST_DB_CREATE_DEPS_SRC	:= $(SRC)db.c $(SRC)db_create.c
TEST_DB_CREATE_DEPS_O	:= $(BUILD)db.o $(BUILD)db_create.o
TEST_DB_CREATE			:= $(BIN)test_db_create


all: $(DIRS) $(TEST_STRUCTS) $(TEST_DB_CREATE) CP_TEST_SCHEMA

$(DIRS):
	mkdir $@

$(TEST_STRUCTS): $(TEST_STRUCTS_SRC)
	$(CC) $(CFLAGS) $(INC) $^ -o $@

$(TEST_DB_CREATE): $(TEST_DB_CREATE_SRC) $(TEST_DB_CREATE_DEPS_SRC)
	$(CC) $(CFLAGS) $(INC) $(LIBS) $^ -o $(TEST_DB_CREATE)

CP_TEST_SCHEMA: $(TEST_SCHEMA)
	cp $< $(BIN)test_schema.sql

# $(TEST_DB_CREATE): $(TEST_DB_CREATE_DEPS_O) $(TEST_DB_CREATE_DEPS_SRC)
#     $(CC) $(CFLAGS) $(INC) $(LIBS) $^ -o $@
#
# $(BUILD)db.o: $(SRC)db.c
#     $(CC) $(CFLAGS) $(INC) $(LIBS) $< -c -o $@
#
# $(BUILD)db_create.o: $(SRC)db_create.c
#     $(CC) $(CFLAGS) $(INC) $(LIBS) $< -c -o $@

clean_all: clean
	rm -rf $(BIN)*

clean:
	rm -rf $(BUILD)*

