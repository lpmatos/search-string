/* #############################################################################
## DESCRIPTION: File Header.
## NAME: file.h
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 16.04.2020
## VERSION: 1.0
##############################################################################*/

#ifndef FILE_H
#define FILE_H

#include <stdbool.h>

FILE *create_file(const char *file_name);
FILE *check_if_file_exist(const char *file_name);

bool check_file_pointer_exist(FILE *file_pointer);

#endif
