#ifndef CUSTOM_LOGGER_H
#define CUSTOM_LOGGER_H
#endif
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

typedef enum { LOG_LEVEL_ERR = 0, LOG_LEVEL_WARN, LOG_LEVEL_INFO } LOG_LEVEL;
void custom_log_write(LOG_LEVEL level, const char *format) ;
