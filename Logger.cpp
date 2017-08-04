/* 
 * File:   Logger.h
 * Author: Gilcesar Avila
 *
 * Created on September 4, 2014, 9:06 PM
 */

#include <Logger.h>
#include <string.h>
#include <stdio.h>

Logger Log = Logger();

void Logger::formatedLog(char * buf, Level level) {
    //time_t tt = now();
    char lev[7];
    switch (level) {
        case TRACE: strcpy(lev, "TRACE ");
            break;
        case DEBUG: strcpy(lev, "DEBUG ");
            break;
        case INFO: strcpy(lev, "INFO  ");
            break;
        case WARN: strcpy(lev, "WARN  ");
            break;
        case ERROR: strcpy(lev, "ERROR ");
            break;
        case FATAL: strcpy(lev, "FATAL ");
            break;
        case OFF: strcpy(lev, "OFF  ");
            break;
    }
    //sprintf(buf, "%02d:%02d:%02d %s", hour(tt), minute(tt), second(tt), lev);
    sprintf(buf, "%02d:%02d:%02d %s", 0, 0, 0, lev);
}

void Logger::log(const char *text, Level level) {
    char fml[20];
    formatedLog(fml, level);
    Serial.print(fml);
    Serial.println(text);
}

Logger::Logger() {
}

void Logger::config(uint64_t speed) {
    Serial.begin(speed);
    info("Logger inicializado!");
}

void Logger::fatal(const char *text) {
    log(text, FATAL);
}

void Logger::error(const char *text) {
    log(text, ERROR);
}

void Logger::warn(const char *text) {
    log(text, WARN);
}

void Logger::info(const char *text) {
    log(text, INFO);
}

void Logger::debug(const char *text) {
    log(text, DEBUG);
}

void Logger::trace(const char *text) {
    log(text, TRACE);
}

void Logger::log(Level level, const char * __fmt, ...) {
    char tmp[200];
    va_list ap;
    va_start(ap, __fmt);
    char fml[20];
    formatedLog(fml, level);
    vsprintf(tmp, __fmt, ap);
    Serial.print(fml);
    Serial.println(tmp);
    va_end(ap);
}

