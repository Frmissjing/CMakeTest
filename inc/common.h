#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gprintf.h>

#define GLIST_TEST
void display_list(GSList *list);
void glist_test1(void);
void glist_test2(void);
void glist_test3(void);
void glist_test4(void);
void glist_test5(void);
void glist_test6(void);

#define GHASHTABLE_TEST
void ghashtable_test1(void);

#endif