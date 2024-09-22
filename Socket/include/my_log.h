#include <stdio.h>

#define INFO 'I'
#define ERROR 'E'

#define LOG_INFO(fmt, ...) printf("%d\t%c\t" fmt "\n", __LINE__, INFO, ##__VA_ARGS__)
#define LOG_ERR(fmt, ...) printf("%d\t%c\t" fmt "\n", __LINE__, ERROR, ##__VA_ARGS__)
