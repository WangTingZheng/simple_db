#include "random.h"

Line *random_initLine(int num)
{
	Line *line = (Line *)malloc(sizeof(Line));
	line->data = (int *)malloc(sizeof(int) * num);
	line->size = num;
	
	for(int i = 0; i < num; i++)
	{
		line->data[i] = rand();
	}
	
	return line;
}	

int random_getInt(Line *line, int pos)
{
	return line->data[pos];
}