#ifndef PINET_LOG_H
#define PINET_LOG_H

#include"log_font.h"
#include"asynclog.h"


#define LOG_ERROR(MSG,arg...) pinet::Logger(__FILE__,__LINE__,pinet::Logger::ERROR,MSG,##arg)
#define LOG_WARN(MSG,arg...)  pinet::Logger(__FILE__,__LINE__,pinet::Logger::WARN,MSG,##arg)
#define LOG_INFO(MSG,arg...)  pinet::Logger(__FILE__,__LINE__,pinet::Logger::INFO,MSG,##arg)
#define LOG_DEBUG(MSG,arg...)  pinet::Logger(__FILE__,__LINE__,pinet::Logger::DEBUG,MSG,##arg)
#endif
