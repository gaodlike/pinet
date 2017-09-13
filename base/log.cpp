#include"log.h"
#include <functional>
pinet::AsyncLog::AsyncLog(const std::__cxx11::string &fileName)
    : fileName(fileName),
      bufMutex(),
      workThread(&AsyncLog::threadFunc,this)
{

    workThread.detach();

}

void pinet::AsyncLog::append(const string &msg){
    std::lock_guard<std::mutex> lockguard(bufMutex);
    (void)lockguard;

    fontBuffer.push_back(std::move(msg));


}

void pinet::AsyncLog::threadFunc(){

    std::ofstream outFile;
    outFile.open(fileName,std::ios_base::app);

    while(true){

        if (!backBuffer.empty()) {
            for(auto it=backBuffer.begin();it!=backBuffer.end();++it){
                std::cout<<*it;
            }
            backBuffer.clear();
        }

        if(!fontBuffer.empty()){
            std::lock_guard<std::mutex> lockguard(bufMutex);
            (void)lockguard;
            swap(backBuffer,fontBuffer);
        }

    }
}
