#ifndef __READINT_H
#define __READINT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LINE Line;

struct LINE
{
	int *  data;
	int    data_size;
	int    real_size;
};

Line* readline_initLine(int data_size);
Line* readline_getIntArray(char *path);
int   readline_getInt(Line *line, int pos);
int   readline_getSize(Line *line);
void  readline_print(Line *line);

Line *readline_merge_path(char **path, int path_num);

#endif