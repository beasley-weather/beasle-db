#include <db_insert.h>


static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }else{
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   return 0;
}


/*
 * Trims trailing comma
 */
void trim_trailing_comma(char *string) {
    int size = strlen(string);
    if (string[size-1] == ' ') {
        string[size-1] = '\0';
    }
}


char* generate_insert_user_labels(struct db_user_entry *entry) {
    char *username   = "username,",
         *pin        = "pin,",
         *name_first = "name_first,",
         *name_last  = "name_last,",
         *home_long  = "home_long,",
         *home_lat   = "home_lat,";

    char values = (char*) malloc(VALUES_LEN);

    if (entry->username != NULL) {
        strcat(values, username);
    }
    if (entry->pin != NULL){
        strcat(values, pin);
    }
    if (entry->name_first != NULL) {
        strcat(values, name_first);
    }
    if (entry->name_last != NULL) {
        strcat(values, name_last);
    }
    if (entry->home_long != NULL) {
        strcat(values, home_long);
    }
    if (entry->home_lat != NULL) {
        strcat(values, home_lat);
    }

    trim_trailing_comma(values);
    return values;
}


char* generate_insert_user_values(struct db_user_entry *entry) {
    int size = 0;
    char *values = (char*) malloc(VALUES_LEN);

    char *val;

    if (entry->username != NULL) {
        strcat(values, entry->username);
        strcat(values, ",");
    }
    if (entry->pin != NULL){
        strcat(values, entry->pin);
        strcat(values, ",");
    }
    if (entry->name_first != NULL) {
        strcat(values, entry->name_first);
        strcat(values, ",");
    }
    if (entry->name_last != NULL) {
        strcat(values, entry->name_last);
        strcat(values, ",");
    }
    if (entry->home_long != NULL) {
        val = sprintf("%f,", entry->home_long);
        strcat(values, val);
        strcat(values, ",");
    }
    if (entry->home_lat != NULL) {
        val = sprintf("%f,", entry->home_lat);
        strcat(values, val);
        strcat(values, ",");
    }

    trim_trailing_comma(values);
    return values;
}


int _db_insert_user_entry(char* db_name, struct db_user_entry *entry) {
    char *labels = generate_insert_user_labels(entry);
    char *data = generate_insert_user_data(entry);
    char sql = sprintf("INSERT INTO (%s) VALUES (%s)", labels, data);
}
