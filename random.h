#ifndef __RANDOM_H
#define __RANDOM_H
#include <stdlib.h>

typedef struct LINE Line;

struct LINE
{
	int *data;
	int size;
};

Line *random_initLine(int num);
int random_getInt(Line *line, int pos);

#endif