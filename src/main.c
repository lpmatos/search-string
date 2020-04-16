/* #############################################################################
## DESCRIPTION: Main context.
## NAME: main.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 15.04.2020
## VERSION: 1.1
##############################################################################*/

#include "log.c"
#include <stdio.h>

#define LOG_USE_COLOR

/* LOGGER FUNCTIONS USAGE
log_trace(const char *fmt, ...);
log_debug(const char *fmt, ...);
log_info(const char *fmt, ...);
log_warn(const char *fmt, ...);
log_error(const char *fmt, ...);
log_fatal(const char *fmt, ...);
*/

int main(int argc, char const *argv[]){
  log_info("Done!");
  return 0;
}

FILE *create_file(const char *file_name){
  log_info("Creating the log File %s!", file_name);
  FILE *file_pointer = NULL;
  file_pointer = fopen(file_name, "w");
  if(!check_file_pointer_exist(file_pointer)){
    log_error("Error while we create the log File %s in the system... Return NULL.", file_name);
    return NULL;
  }else{
    log_info("Success in creating the log File %s in the system!", file_name);
    return file_pointer;
  }
}

// =============================================================================

FILE *check_file_exist(const char *file_name){
  log_info("Checking if the %s alredy exist in the system", file_name);
  if(!access(file_name, F_OK )){
    log_info("The log File %s was Found in the system!", file_name);
    return NULL;
  }else{
    log_info("The log File %s not Found in the system. We will this file for you.", file_name);
    FILE *file_pointer = create_file(file_name);
    return file_pointer;
  }
}
