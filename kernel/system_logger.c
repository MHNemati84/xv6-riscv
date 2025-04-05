 #include "types.h"
#include "riscv.h"
#include "system_logger.h"
#include "defs.h"




struct Logger{
    char buffer[BUFFER_SIZE];
    int start;
    int end;
    Level level;
}logger;

void logger_init(){
    logger.start = 0;
    logger.end = 0;
}
void logger_message(Level level,const char *message){
    // storing the log
    if(level != OTHER){
        logger.level = level;
        int i = 0;
        while(logger.end + 1 < BUFFER_SIZE && logger.start + 1 < BUFFER_SIZE && message[i] != '\0'){
            logger.buffer[logger.end] = message[i];
            i += 1;
            logger.end += 1;
        }

        //printing out the log message
        const char *prefix;
        switch(logger.level){
            case INFO:
                prefix = "\033[32mINFO-\033[0m";
                break;
            case WARNING:
                prefix = "\033[33mWARNING-\033[0m";
                break;
            case ERROR:
                prefix = "\033[31mERROR-\033[0m";
                break;
            default:
                prefix = "";
                break;
        }
        
        i = 0;
        while(prefix[i] != '\0'){
            consputc(prefix[i]);
            i += 1;
        }

        i = logger.start;
        while(i <= logger.end){
            consputc(logger.buffer[i]);
            i += 1;
        }
        
        consputc('\n');
    

        logger.start = logger.end + 1;
        logger.end = logger.end + 1;

        
    }

}