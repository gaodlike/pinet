#include"log_font.h"
#include <boost/format.hpp>

#include "time_helper.h"
#include<stdarg.h>
#include<cstring>


namespace pinet{

const static char LevelStr[][16]={
    "TRACE",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL",
};

    static void defaultOutput(const string &msg){
        std::cout<<msg;
    }
    Logger::OutFunc Logger::outfunc=defaultOutput;
    static string getNowTime()
    {
        struct timeval tv;

        gettimeofday(&tv, NULL);

    
        mytime_struct ts;
        utc_sec_2_mytime(tv.tv_sec, &ts, false);
        string ret = (boost::format("%d/%d/%d %d:%d:%d") % ts.nYear % int(ts.nMonth) % int(ts.nDay) % int(ts.nHour) % int(ts.nMin) % int(ts.nSec)).str();
    
    
    
        return ret;
    }
    
    static string getThreadId()
    {
        return (boost::format("%d")%getpid()).str();
    }


    Logger::Logger(const char*fileName, int line, LogLevel level, const char*info,...)
    {


        char enter[]="\n";
        char buff[LOG_MAX_LEN]="";


        std::sprintf(buff,"%s %d %d %s %s ",fileName,line,getThreadId(),getNowTime().c_str(),LevelStr[level]);


        va_list arglist;
        va_start(arglist, info);


        std::vsprintf(buff+strlen(buff),info,arglist);
        va_end(arglist);

        strcat(buff,enter);
        

        outfunc(buff);
    }

    void Logger::setOutput(Logger::OutFunc f)
    {
        outfunc=f;
    }

    Logger::OutFunc outfunc=defaultOutput;




}
