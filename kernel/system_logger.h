#ifndef SYSTEM_LOGGER_H
#define SYSTEM_LOGGER_H

#include "types.h"
#define BUFFER_SIZE 100000

typedef enum{
    INFO,
    WARNING,
    ERROR,
    OTHER
} Level;

void logger_message(Level level , const char * message);
void logger_init();

#endif