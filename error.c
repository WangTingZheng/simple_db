#include <stdio.h>
#include "error.h"

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

void db_perror(char *str)
{
	if(errno) printf("%s", db_streror(errno));
	else printf("%s", str);
}

void db_cerror()
{
	errno = 0;
}