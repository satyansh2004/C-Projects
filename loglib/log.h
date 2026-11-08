#ifndef LOG_LIB
#define LOG_LIB

#ifndef ENABLE_LOG
  #define ENABLE_LOG 0
#endif

typedef enum {

  LOG_INFO,
  LOG_WARN,
  LOG_ERROR,

}_LOG_TYPE;

void print_log(char *log_message, _LOG_TYPE log_type);

#endif
