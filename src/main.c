/* #############################################################################
## DESCRIPTION: Main context.
## NAME: main.c
## AUTHOR: Lucca Pessoa da Silva Matos
## DATE: 16.04.2020
## VERSION: 1.0
##############################################################################*/

#include <omp.h>
#include "./lib/settings/log/log.c"
#include "./lib/settings/base/base.c"
#include "./lib/settings/file/file.c"

#define NUM_THREADS 12

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

  int arg, n_threads, found = 0, counter = 1, swap = 1;
  char w2f[256], dir[100] = "logs\\", *file_name = "validation.log", opc;

  strcat(dir, file_name);
  system("mkdir logs");

  FILE *file_log = check_if_file_exist(dir);
  file_log = fopen(dir, "a+");

  log_set_fp(file_log);

  printf("\n");

  memset(w2f,0,strlen(w2f));

  while(1){
    printf("Please tell me what word you want to find - Couter %d: ", counter);
    gets(w2f);
    if(w2f[0] == '\0'){
      memset(w2f,0,strlen(w2f));
      counter++;
      continue;
    }else{
      break;
    }
  }

  printf("\nCool! Your world is: %s", w2f);
  strtok(w2f, "\n");

  printf("\n\n");

  while(swap){
    printf("Do you want to set the number of threads used in the program or use the standard number? <Y> or <N>: ");
    scanf("%c", &opc);
    switch (opc){
      case 'Y':
      {
        printf("\nEnter with the number of threads: ");
        scanf("%d", &n_threads);
        printf("\n");
        swap = 0;
        break;
      }
      case 'N':
      {
        n_threads = NUM_THREADS;
        printf("\nWe will use the default quantity!\n\n");
        swap = 0;
        break;
      }
      default:
        continue;
      }
  }

  if(argc > 1){
    for (int arg = 1; arg < argc; ++arg){
      if(strcmp("-f", argv[arg]) == 0){
        const char *param = argv[2];
        if(param){
          FILE *file_to_search = check_if_file_exist(param);
          file_to_search = fopen(param, "r");
          int window = strlen(w2f);
          int end_file_to_search = get_file_total_lines(file_to_search);
          double start_time = omp_get_wtime();
          #pragma omp parallel num_threads(n_threads)
          {
            FILE *file_to_search_thread;
            file_to_search_thread = fopen(param, "r");
            int id = omp_get_thread_num();
            int total_threads = omp_get_num_threads();
            int start, end, division, mod;
            division = end_file_to_search / total_threads;
            mod = end_file_to_search % total_threads;
            start = (id - 1) * division;
            end = id * division;
            #pragma omp master
            {
              start = end_file_to_search - (division + mod);
              end = end_file_to_search;
            }
            #pragma omp barrier
            fseek(file_to_search_thread, start, SEEK_CUR);
            for (int i = start; i < end; ++i) {
              char word[window];
              fgets(word, window + 1, file_to_search_thread);
              if (word[strlen(word) -1 ] != '\n') fseek(file_to_search_thread, -window + 1, SEEK_CUR);
              if (strcmp (word, w2f) == 0) found = 1;
            }
          }
          double end_time = omp_get_wtime() - start_time;
          if (found == 1) {
            printf("\n-> Yeaaaaah! The word '%s' was found!", w2f);
          } else {
            printf("\n-> Sorry... Word not found!!!");
          }
          printf("\n");
          printf("\nTempo final: %lf\n\n", end_time);

        }else{
          printf("\nHey! Sorry, a need a file param. Please, check this helper:\n");
          helper();
        }
        break;
      }else if(strcmp("-h", argv[arg]) == 0){
        printf("\nHey! This is the helper:\n");
        helper();
        break;
      }
      else{
        printf("\nHey! Sorry, we dont have this param. Please, check this helper:\n");
        helper();
        break;
      }
    }
  }else{
    printf("\nHey! Sorry, we need some params... Please, check this helper:\n");
    helper();
  }

  return 0;
}
