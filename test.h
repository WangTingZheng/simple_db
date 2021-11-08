#ifndef __TEST_H
#define __TEST_H
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>
#include <stdio.h>

#include "db.h"
#include "readint.h"

typedef struct DINFO DInfo;

struct DINFO
{
  char **path;
  int path_num;
  int int_num;
  int int_max;
  int dup_key;
};

long test_delete(void (*f_delete)(int), DInfo dinfo);

#endif