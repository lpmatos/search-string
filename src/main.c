/* #############################################################################
## DESCRIPTION: Main context.
## NAME: main.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 15.04.2020
## VERSION: 1.1
##############################################################################*/

#include "log.c"
#include "base.c"
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
  set_portuguese();
  cabecalho();
  log_info("Done!");
  return 0;
}
