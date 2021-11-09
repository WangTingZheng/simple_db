#include "test.h"


long test_delete(void (*f_delete)(int), DInfo dinfo)
{
	int int_num  = dinfo.int_num;
	int int_max  = dinfo.int_max;
	int dup_key  = dinfo.dup_key;
	
	struct timeval start,end;  
	Line *line = random_initLine(int_num);
	int key = 0;
	

	db_init(line->size);

	for(int i = 0; i < int_num; i++)
	{
		key = random_getInt(line, i);
		if(int_max > 0) key %= int_max;
		db_set(key, key);
	}
	
	gettimeofday(&start, NULL);  
	f_delete(dup_key);
	gettimeofday(&end, NULL);  

	long timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; 
	
	db_cerror();
	db_get(dup_key);
	if(!errno)
	{
		printf("Still has %d not be delete!\n", dup_key);
		return -1;
	}
	
	db_free();

	return timeuse;
}