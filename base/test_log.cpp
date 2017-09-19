#include"log_font.h"
#include"log.h"
#include<sstream>
pinet::AsyncLog l("log.txt");

void asyncOutput(const string&msg)
{
  l.append(msg);
}


void  func(){

    for(int i=0;i<100;i++){
        std::stringstream s;

        std::thread::id id=std::this_thread::get_id();
        s<<"thread id: "<<id;
        string ss=s.str();
        LOG_DEBUG(ss.c_str());
}


}

static char msg[]="xxx";

int main(){


    pinet::Logger::setOutput(asyncOutput);

    for(int i=0;i<1;i++){
        std::thread *t=new std::thread(func);
        t->join();
    }





    return 0;
}
