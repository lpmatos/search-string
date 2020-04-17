/* #############################################################################
## DESCRIPTION: In this file we build the functions presente in base.h.
## NAME: base.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 16.04.2020
## VERSION: 1.0
##############################################################################*/

#include <stdio.h>
#include <locale.h>
#include <unistd.h>

#include "../../../include/base.h"

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
    "  -h            This help message.\n\n");
  exit(EXIT_FAILURE);
}

// =============================================================================

void header_description(void){
  printf("\n**************************************************");
  printf("\n*                                                *");
  printf("\n* DESCRIPTION: IMPLEMENTATION  - SEARCH STRING   *");
  printf("\n* AUTOR: LUCCA PESSOA DA SILVA MATOS             *");
  printf("\n* DATE: 16-04-2020                               *");
  printf("\n*                                                *");
  printf("\n**************************************************\n\n");
}
