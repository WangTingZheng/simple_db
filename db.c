#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "db.h"

char *db_streror(int errnum)
{
  switch(errnum)
  {
	case 1:
	{
		return "execute failed, array is full.\n";
	}
	
	case 2:
	{
		return "execute failed, data not in the array.\n";
	}
	
	default: return "";
  }
}

void db_perror()
{
	printf("%s", db_streror(errno));
}

void db_cerror()
{
	errno = 0;
}

void db_init(int size)
{
  database.data = (KVNode *)malloc(sizeof(KVNode) * size);
  database.size = size;
  database.current_size = 0;
  db_cerror();
}

void db_set(int key, int value)
{
    if(database.current_size < database.size)
	{
	  database.data[database.current_size].key = key;
	  database.data[database.current_size].value = value;
	  database.current_size ++;
	}else
	{
		errno = 1;
	}
}

int db_get(int key)
{
	for(int i = 0; i < database.current_size; i++)
	{
	  if(database.data[i].key == key) return database.data[i].value;
	}
	
	errno = 2;
	return 0;
}

void db_update(int key, int value)
{
	for(int i = 0; i < database.current_size; i++)
	{
		if(database.data[i].key == key) database.data[i].value = value;
	}
	
	errno = 2;
}

void db_delete(int key)
{
    for(int i = 0; i < database.current_size; i++)
    {
      if(database.data[i].key == key)
	  {
	    while(database.current_size >= 1 && database.data[database.current_size - 1].key == key){
			database.current_size -= 1;
		}
	    database.data[i].key   = database.data[database.current_size - 1].key;
		database.data[i].value = database.data[database.current_size - 1].value;
		database.current_size -= 1;
	  }
    }
	
	errno = 2;
}

void db_delete2(int key)
{
	int sorted = 0;
	
	for(int pos = 0; pos < database.current_size; pos++)
	{
		if(database.data[pos].key != key)
		{
			database.data[sorted].key = database.data[pos].key;
			database.data[sorted].value = database.data[pos].value;
			sorted ++;
		}
	}
	
	database.current_size = sorted;
	
	if(sorted == database.current_size) errno = 2;
}

void db_free()
{
	free(database.data);
}