#include <stdarg.h>
#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "defs.h"
#include "custom_logger.h"

void custom_log_write(LOG_LEVEL level, const char *format) {
  static int count;
  const char *color;
  const char *label;
  switch (level) {
  default:
    color = WHITE;
    label = "UNKNOWN_LOG";
    break;
  case LOG_LEVEL_ERR:
    color = RED;
    label = "ERROR";
    break;
  case LOG_LEVEL_WARN:
    color = YELLOW;
    label = "WARNING";
    break;
  case LOG_LEVEL_INFO:
    color = GREEN;
    label = "INFO";
    break;
  }
  printf("%s%d: %s--: ", color, count, label);
  printf("%s",format);
  printf("\033[0m\n");

  count++;
}
