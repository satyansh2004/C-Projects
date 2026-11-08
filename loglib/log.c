#include <stdio.h>
#include "log.h"

#define UNUSED(x) (void)(x)

#define COLOR_RED     "\x1b[31m"
#define COLOR_YELLOW     "\x1b[33m"
#define COLOR_LIGHT_BLUE     "\x1b[94m"
#define COLOR_RESET   "\x1b[0m"

#if ENABLE_LOG == 1
void print_log(char *log_message, _LOG_TYPE log_type) {

  if (log_type == LOG_INFO) {
    printf(COLOR_LIGHT_BLUE "[INF] %s\n" COLOR_RESET, log_message);
  }

  else if (log_type == LOG_WARN) {
    printf(COLOR_YELLOW "[WRN] %s\n" COLOR_RESET, log_message);
  }

  else if (log_type == LOG_ERROR) {
    printf(COLOR_RED "[ERR] %s\n" COLOR_RESET, log_message);
  }

}

#else
void print_log(char *log_message, _LOG_TYPE log_type) {
  UNUSED(log_message);
  UNUSED(log_type);
  return;
}
#endif
