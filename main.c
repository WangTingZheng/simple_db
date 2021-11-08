#include <stdio.h>

#include "test.h"
#include "db.h"
#include "readint.h"

void main()
{
	 DInfo dinfo;
	 
	 dinfo.path_num = 6;	 
	 dinfo.path = (char **)malloc(sizeof(char*) * dinfo.path_num);
	 dinfo.path[0] = "/root/c/cs61b/simple_db/data/1.txt";
	 dinfo.path[1] = "/root/c/cs61b/simple_db/data/2.txt";
	 dinfo.path[2] = "/root/c/cs61b/simple_db/data/3.txt";
	 dinfo.path[3] = "/root/c/cs61b/simple_db/data/4.txt";
	 dinfo.path[4] = "/root/c/cs61b/simple_db/data/5.txt";
	 dinfo.path[5] = "/root/c/cs61b/simple_db/data/6.txt";
	 
	 dinfo.int_num  = 1000000;
	 dinfo.int_max  = 20;
	 dinfo.dup_key  = 1;
	 
	 long time1 = test_delete(db_delete , dinfo);
	 long time2 = test_delete(db_delete2, dinfo);
	 long time3 = test_delete(db_delete3, dinfo);
	 
	 printf("time1 is %ld\n", time1);
	 printf("time2 is %ld\n", time2);
	 printf("time3 is %ld\n", time3);
}