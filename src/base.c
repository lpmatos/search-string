/* #############################################################################
## DESCRIPTION: Base Functions Definition.
## NAME: base.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 16.04.2020
## VERSION: 1.1
##############################################################################*/

#include "base.h"
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <stdbool.h>


// =============================================================================
// FUNCTIONS
// =============================================================================

void set_portuguese(void){
  setlocale(LC_ALL, "Portuguese");
}

// =============================================================================

void helper(void){
  printf(
    "\n"
    "Usage:\n"
    "     ./main [ -f file] [-h]\n"
    "\n"
    "Options:\n"
    "  -f    file    Path file.\n"
    "  -h            This help message.\n");
  exit(EXIT_FAILURE);
}

// =============================================================================

void cabecalho(void){
  printf("\n**************************************************");
  printf("\n*                                                *");
  printf("\n* DESCRIPTION: IMPLEMENTATION  - SEARCH STRING   *");
  printf("\n* AUTOR: LUCCA PESSOA DA SILVA MATOS             *");
  printf("\n* DATE: 16-04-2020                               *");
  printf("\n*                                                *");
  printf("\n**************************************************\n\n");
}

// =============================================================================

bool check_file_pointer_exist(FILE *file_pointer){
  return file_pointer ? true : false;
}
