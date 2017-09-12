#ifndef PINET_LOG_FONT_H
#define PINET_LOG_FONT_H

#include <sys/time.h>

#include <string>
#include <sstream>

#include <boost/format.hpp>

#include "time_helper.h"

#define LOG_MAX_LEN = 1024;

using namespace std;

namespace pinet
{
static string getNowTime()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    int secNum = tv.tv_sec;

    mytime_struct ts;
    utc_sec_2_mytime(tv.tv_sec, &ts, false);
    string ret = (boost::format("%d/%d/%d %d/%d/%d") % ts.nYear % ts.nMonth % ts.nDay % ts.nHour % ts.nMin % ts.nSec).str();



    return ret;
}

static string getThreadId()
{
    return (boost::format("%d")%getpid()).str();
}

class Logger
{
  public:
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
    Logger(const char*fileName, int line, LogLevel level, const char*info)
    {
        int l=(int)level;
        string msg=
        (boost::format("%s %d %d %s %d %s")%fileName%line%getNowTime()%l%info).str();
        

        outFunc(string);
    }

private:
    typedef void(*outFunc)(const string&msg);


};
}

#define LOG_ERROR(MSG) Logger(__FILE__,__LINE__,pinet::Logger::ERROR,MSG)
#define LOG_WARN(MSG)  Logger(__FILE__,__LINE__,pinet::Logger::WARN,MSG)
#define LOG_INFO(MSG)  Logger(__FILE__,__LINE__,pinet::Logger::INFO,MSG)
#define LOG_DEBUG(MSG)  Logger(__FILE__,__LINE__,pinet::Logger::DEBUG,MSG)

#endif