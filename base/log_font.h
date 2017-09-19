#ifndef PINET_LOG_FONT_H
#define PINET_LOG_FONT_H

#include <sys/time.h>

#include <string>
#include <sstream>
#include<iostream>


#define LOG_MAX_LEN   1024

using namespace std;

namespace pinet
{


class Logger
{
  public:
    typedef void(*OutFunc)(const string&);
    typedef void(*FlushFunc)();
    enum LogLevel
    {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL,
        NUM_LOG_LEVELS,

    };




    Logger(const char*fileName, int line, LogLevel level, const char*info,...);

    static void setOutput(OutFunc);
    static void setOutput(FlushFunc);
private:
    
    static OutFunc outfunc;
    static FlushFunc flushfunc;

};
}



#endif
