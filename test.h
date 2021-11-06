#ifndef __TEST_H
#define __TEST_H

void test_init(int size);
int  test_register(int username, int password);
int  test_login(int username, int password);
int  test_change(int username, int password);
int  test_logout(int username, int password);
void test_exit();

#endif