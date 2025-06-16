#include "functions.c"

int main ()
{
	databaseType db;
	db.employeeCtr = 0;

	srand(time(NULL));
	mainMenu(&db);

	return 0;
}
