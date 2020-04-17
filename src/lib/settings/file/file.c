/* #############################################################################
## DESCRIPTION: In this file we build the functions presente in file.h.
## NAME: file.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 16.04.2020
## VERSION: 1.0
##############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../../../include/log.h"
#include "../../../include/file.h"

/* LOGGER FUNCTIONS USAGE
log_trace(const char *fmt, ...);
log_debug(const char *fmt, ...);
log_info(const char *fmt, ...);
log_warn(const char *fmt, ...);
log_error(const char *fmt, ...);
log_fatal(const char *fmt, ...);
*/

// =============================================================================
// FUNCTIONS
// =============================================================================

bool check_file_pointer_exist(FILE *file_pointer){
  return file_pointer ? true : false;
}

// =============================================================================

FILE *create_file(const char *file_name){
  log_info("Creating the File!");
  FILE *file_pointer = NULL;
  file_pointer = fopen(file_name, "w");
  if(!check_file_pointer_exist(file_pointer)){
    log_info("Error creating File... Return NULL.");
    return NULL;
  }else{
    log_info("File creation successful!");
    return file_pointer;
  }
}

// =============================================================================

FILE *check_if_file_exist(const char *file_name){
  log_info("Checking if File alredy exist.");
  if(!access(file_name, F_OK )){
    log_info("File was found in the system!");
    return NULL;
  }else{
    log_info("File not found in the system. We will create for you.");
    FILE *file_pointer = create_file(file_name);
    return file_pointer;
  }
}

// =============================================================================

int get_file_total_lines(FILE *file_pointer){
  /* Pula até o fim do arquivo.*/
  fseek(file_pointer, 0, SEEK_END);
  /* Lê o indicador de posição (em bytes).*/
  return ftell(file_pointer);
}
