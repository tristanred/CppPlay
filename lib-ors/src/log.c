#include "log.h"

#include <stdio.h>

void log_trace(char* msg) {
#if _TRACE
  printf("TRACE: %s\n", msg);
#else
  (void)msg;
#endif
}

void log_debug(char* msg) {
#if DEBUG
  printf("DEBUG: %s\n", msg);
#else
  (void)(msg);
#endif
}

void log_info(char* msg) {
  printf("INFO: %s\n", msg);
}

void log_warning(char* msg) {
  printf("WARN: %s\n", msg);
}

void log_error(char* msg) {
  printf("ERROR: %s\n", msg);
}
