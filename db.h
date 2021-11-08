#ifndef __DB_H
#define __DB_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct KVNODE KVNode;
typedef struct DATABASE Database;

struct KVNODE{
  int key;
  int value;
};

struct DATABASE{
  KVNode *data;
  int size;
  int current_size;
};

Database database;

void db_perror();
void db_cerror();

void db_init(int size);
void db_set(int key, int value);
int  db_get(int key);
void db_update(int key, int value);
void db_delete(int key);
void db_delete2(int key);
void db_delete3(int key);
void db_free();

#endif