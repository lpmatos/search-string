/* #############################################################################
## DESCRIPTION: Main context.
## NAME: main.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 15.04.2020
## VERSION: 1.1
##############################################################################*/

#include "./lib/settings/log/log.c"
#include "./lib/settings/base/base.c"
#include "./lib/settings/file/file.c"

#define LOG_USE_COLOR

/* LOGGER FUNCTIONS USAGE
log_trace(const char *fmt, ...);
log_debug(const char *fmt, ...);
log_info(const char *fmt, ...);
log_warn(const char *fmt, ...);
log_error(const char *fmt, ...);
log_fatal(const char *fmt, ...);
*/

// =============================================================================
// MAIN
// =============================================================================

int main(int argc, char const *argv[]){

  set_portuguese();
  header_description();

  char dir[100] = "logs\\";
  char *file_name = "validation.log";

  strcat(dir, file_name);

  system("mkdir logs");

  FILE *file_pointer = check_if_file_exist(dir);
  file_pointer = fopen(dir, "a+");

  log_set_fp(file_pointer);

  int arg;

  if(argc > 1){
    for (int arg = 1; arg < argc; ++arg){
      if(strcmp("-f", argv[arg]) == 0){
        printf("argv[%d]: %s\n", arg, argv[arg]);
        log_info("File");
        break;
      }else if(strcmp("-h", argv[arg]) == 0){
        printf("Hey! This is the helper:\n");
        log_info("Helper");
        helper();
        break;
      }
      else{
        printf("Hey! Sorry, we dont have this param. Please, check this helper:\n");
        helper();
        break;
      }
    }
  }else{
    printf("Hey! Sorry, we need some params... Please, check this helper:\n");
    helper();
  }

  return 0;
}
