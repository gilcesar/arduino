/* 
 * File:   Logger.h
 * Author: Gilcesar Avila
 *
 * Created on September 4, 2014, 9:06 PM
 */

#ifndef Logger_H
#define	Logger_H

#include <inttypes.h>
#include <HardwareSerial.h>
extern HardwareSerial Serial;

enum Level {
    TRACE, DEBUG, INFO, WARN, ERROR, FATAL, OFF
};

class Logger {

    void formatedLog(char * buf, Level level);

    void log(const char *text, Level level);

public:
    Logger();
    void config(uint64_t speed);

    void fatal(const char *text);

    void error(const char *text);

    void warn(const char *text);

    void info(const char *text);

    void debug(const char *text);

    void trace(const char *text);

    void log(Level level, const char * __fmt, ...);

}extern Log;


#endif	/* Logger_H */

