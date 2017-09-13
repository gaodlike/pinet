#ifndef PINET_LOG_H
#define PINET_LOG_H

#include<queue>
#include<string>
#include<iostream>
#include<fstream>
#include <thread>
#include<mutex>


#include<boost/core/noncopyable.hpp>

using namespace std;

namespace pinet{


    //memory pool or allocator?

    class LogBuffer:public vector<string> ,boost::noncopyable
    {
    public:
        LogBuffer()
        :vector<string>()
        {
            reserve(40);
        }
    };

    class AsyncLog{

    public:
        AsyncLog (const string &fileName);

        void append(const string&msg);

    private:

        void threadFunc();

        string fileName;

        LogBuffer fontBuffer;
        LogBuffer backBuffer;
        std::mutex bufMutex;
        std::thread workThread;
        
    };
}

#endif
