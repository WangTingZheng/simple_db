#include "readint.h"

Line* readline_initLine(int data_size)
{
	Line * line = (Line *)malloc(sizeof(Line));
	
	line->data_size = data_size;
	line->real_size = 0;
	
	line->data = (int *)malloc(sizeof(int) * data_size);
	
	return line;
}

int readline_charToInt(char *buf)
{
	int i = 0;
	memcpy(&i, buf, 4);
	
	return i;
}

int readline_caluFileSize(char *path)
{
	FILE *in   = fopen(path, "rb");
	if(in == NULL)
	{
		puts("failed to open a file");
		return 0;
	}
	
	char ch;
	int num = 0;
	int sum = 0;
	int n = 0;
	
	char *buf = (char *)malloc(sizeof(char) * 4);
	
	for(int i = 0; i < 4; i++)
	{
		while((ch = fgetc(in)) != EOF)
		{
			if(ch > 0 && n >= i)
			{
				buf[sum] = ch;
				sum ++;
			
				if(sum == 4)
				{
					num ++;
					sum = 0;
				}
				
			}
			n ++;
		}
		fclose(in);
		in = fopen(path, "rb");
		n = 0;
	}
	
	return num;
}

Line* readline_getIntArray(char *path)
{
	int size = readline_caluFileSize(path);
	Line *line = readline_initLine(size);
	FILE *in   = fopen(path, "rb");
	
	char ch;
	int num = 0;
	int sum = 0;
	int n = 0;
	
	char *buf = (char *)malloc(sizeof(char) * 4);
	
	if(in == NULL)
	{
		puts("failed to open a file");
		return NULL;	
	}
	
	for(int i = 0; i < 4; i++)
	{
		while((ch = fgetc(in)) != EOF)
		{
			if(ch > 0 && n >= i)
			{
				buf[sum] = ch;
				sum ++;
			
				if(sum == 4)
				{
					line->data[num] = readline_charToInt(buf);
					num ++;
					sum = 0;
				}
				
			}
			n ++;
		}
		fclose(in);
		in = fopen(path, "rb");
		n = 0;
	}
	
	line->real_size = num;
	
	fclose(in);
    
    return line;
}

Line *readline_merge(Line *line1, Line *line2)
{
	Line *line = (Line*)malloc(sizeof(Line));
	line->real_size = line1->real_size + line2->real_size;
	line->data = (int *)malloc(sizeof(int) * (line->real_size));

	for(int i=0; i < line->real_size; i++)
	{
		if(i % (line1->real_size - 1) == i)
			line->data[i] = line1->data[i];
		else
			line->data[i] = line2->data[i % ((line1->real_size) - 1)];
	}
	
	return line;
}

Line *readline_merge_path(char **path, int path_num)
{
	if(path_num == 0) return readline_initLine(0);
	else if(path_num == 1) return readline_getIntArray(path[0]);
	
	Line *line = readline_merge(readline_getIntArray(path[0]), readline_getIntArray(path[1]));
	
	for(int i = 2; i < path_num; i++)
	{
		line = readline_merge(line, readline_getIntArray(path[i]));
	}
	
	return line;
}

int readline_getInt(Line *line, int pos)
{
	return line->data[pos];
}

int readline_getSize(Line *line)
{
	return line->real_size;
}

void readline_print(Line *line)
{
	for(int i = 0; i < line->real_size; i++)
	{
		printf("NO %d line is %d\n",i, line->data[i]);
	}
}

/*
void main()
{
	char *path1 = "/root/c/cs61b/simple_db/data/1.txt";
	char *path2 = "/root/c/cs61b/simple_db/data/2.txt";
	char *path3 = "/root/c/cs61b/simple_db/data/3.txt";
	char *path4 = "/root/c/cs61b/simple_db/data/4.txt";
	char *path5 = "/root/c/cs61b/simple_db/data/5.txt";
	char *path6 = "/root/c/cs61b/simple_db/data/6.txt";
	char **path    = (char **)malloc(sizeof(char *) * 6);
	
	path[0] = path1;
	path[1] = path2;
	path[2] = path3;
	path[3] = path4;
	path[4] = path5;
	path[5] = path6;
	
	Line *line = readline_merge_path(path, 6);
	//	readline_print(line);
	printf("size %d\n", readline_getSize(line));
}*/