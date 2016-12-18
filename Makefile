CC = gcc
LIB_SQLITE = -l sqlite3


BIN			= bin/
SRC			= src/

DB_EXEC     = $(BIN)db
CREATE_EXEC = $(BIN)db_create
INSERT_EXEC = $(BIN)db_insert
SELECT_EXEC = $(BIN)db_select
EXECS       = $(DB_EXEC) $(CREATE_EXEC) $(INSERT_EXEC) $(SELECT_EXEC)

DB_C        = $(SRC)db.c
CREATE_C    = $(SRC)db_create.c
INSERT_C    = $(SRC)db_insert.c
SELECT_C    = $(SRC)db_select.c


all: bin_dir create insert select

bin_dir:
	mkdir -p $(BIN)

create:
	$(CC) $(LIB_SQLITE) $(CREATE_C) -o $(CREATE_EXEC)

insert:
	$(CC) $(LIB_SQLITE) $(INSERT_C) -o $(INSERT_EXEC)

select:
	$(CC) $(LIB_SQLITE) $(SELECT_C) -o $(SELECT_EXEC)

clean:
	rm -f $(EXECS)
	rm -f $(BIN)*.db
	rmdir -p $(BIN)
