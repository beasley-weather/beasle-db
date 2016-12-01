CC = gcc
LIB_SQLITE = -l sqlite3


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
	$(CC) $(DB_C) -o $(DB_EXEC)

create:
	$(CC) $(LIB_SQLITE) $(CREATE_C) -o $(CREATE_EXEC)

insert:
	$(CC) $(LIB_SQLITE) $(INSERT_C) -o $(INSERT_EXEC)

select:
	$(CC) $(LIB_SQLITE) $(SELECT_C) -o $(SELECT_EXEC)

clean:
	rm -f $(EXECS)
