#ifndef __TEST_H
#define __TEST_H
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>
#include <stdio.h>

#include "db.h"
#include "random.h"

typedef struct DINFO DInfo;

struct DINFO
{
  int int_num;
  int int_max;
  int dup_key;
};

long test_delete(void (*f_delete)(int), DInfo dinfo);

#endif