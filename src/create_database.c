#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int check_arg(int argc, char* argv[])
{
    if (argc != 2)
        return -1;
    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i=0; i<argc; i++)
   {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int  rc;
   char *sql;

   int arg_status = check_arg(argc, argv);
   if (arg_status)
       goto ARG_ERR;

   /* Open database */
   rc = sqlite3_open(argv[1], &db);
   if( rc )
   {
      printf("Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }
   else
   {
      printf("Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK )
   {
      printf("SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
      printf("Table created successfully\n");
   }

   sqlite3_close(db);
   return 0;

   ARG_ERR:
      printf("Invalid argument,\nusage: create_database db_name\n");
      return 1;
}
