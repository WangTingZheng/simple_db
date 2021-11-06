#include "db.h"

void test_init(int size)
{
	db_init(size);
}

int test_register(int username, int password)
{
	db_cerror();
	db_get(username);
	if(errno)
	{
		db_set(username, password);
		return 1;
	}else return 0;
}

int test_login(int username, int password)
{
	db_cerror();
	int password_g = db_get(username);
	if(errno) return 0;
	else
	{
		if(password_g == password) return 1;
		return 0;
	}
}

int test_change(int username, int password)
{
	db_cerror();
	db_get(username);
	
	if(errno)
	{
		db_update(username, password);
		return 1;
	}
	
	return 0;
}

int test_logout(int username, int password)
{
	db_cerror();
	db_get(username);
	
	if(errno)
	{
		db_delete(username);
		return 1;
	}
	
	return 0;
}

void test_exit()
{
	db_free();
}