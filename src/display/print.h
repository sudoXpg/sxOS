#ifndef PRINT_H
#define PRINT_H

#include <stddef.h>
#include <stdint.h>

#include "../config.h"

void termial_init();
void print(const char *s);
void write_char(char c,char color);

#endif