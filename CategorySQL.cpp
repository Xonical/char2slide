#include "CategorySQL.h"


CategorySQL::CategorySQL(string query)
{
	SQLiteOpen("mydatabase.db");

}


CategorySQL::~CategorySQL()
{
}
