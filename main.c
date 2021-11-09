#include <stdio.h>

#include "test.h"
#include "db.h"
#include "random.h"

void main()
{
	 DInfo dinfo;
	 
	 dinfo.int_num = 1000000;
	 dinfo.int_max = -1;
	 dinfo.dup_key = 123201;
	 
	 long time1 = test_delete(db_delete , dinfo);
	 long time2 = test_delete(db_delete2, dinfo);
	 long time3 = test_delete(db_delete3, dinfo);
	 
	 printf("time1 is %ld\n", time1);
	 printf("time2 is %ld\n", time2);
	 printf("time3 is %ld\n", time3);
}