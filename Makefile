CC = gcc
LIB_SQLITE = -l sqlite3
LIB_SQLITE_PATH = -L /usr/lib/i386-linux-gnu/

DB_EXEC     = db
CREATE_EXEC = db_create
INSERT_EXEC = db_insert
SELECT_EXEC = db_select
EXECS       = $(DB_EXEC) $(CREATE_EXEC) $(INSERT_EXEC) $(SELECT_EXEC)

DB_C        = $(DB_EXEC).c
CREATE_C    = $(CREATE_EXEC).c
INSERT_C    = $(INSERT_EXEC).c
SELECT_C    = $(SELECT_EXEC).c


db: create insert select
	$(CC) $(DB_C) -o $(DB_EXEC) $(LIB_SQLITE_PATH) $(LIB_SQLITE) 

create:
	$(CC) $(CREATE_C) -o $(CREATE_EXEC) $(LIB_SQLITE_PATH) $(LIB_SQLITE) 

insert:
	$(CC) $(INSERT_C) -o $(INSERT_EXEC) $(LIB_SQLITE_PATH) $(LIB_SQLITE)

select:
	$(CC) $(SELECT_C) -o $(SELECT_EXEC) $(LIB_SQLITE_PATH) $(LIB_SQLITE)

clean:
	rm -f $(EXECS)
