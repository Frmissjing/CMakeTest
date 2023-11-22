#ifndef KEYFILE_API_H
#define KEYFILE_API_H

#include <glib.h>
#include <stdio.h>

GKeyFile* storage_open(const char *imsi, const char *store);

void print_test();



#endif

