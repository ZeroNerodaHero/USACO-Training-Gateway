#ifndef _BPROF_HEADER_
#define _BPROF_HEADER_

#include <iostream>
#include <time.h>

#define PROFILE_START clock_t t1 = clock();

#define PROFILE_STOP\
    clock_t t2 = clock();\
    long diff = (t2-t1)*1000000/CLOCKS_PER_SEC;\
    cout <<"time:\t" <<diff << endl;

#define PROFILE(x)\
    do{\
        clock_t t1, t2;\
        t1 = clock();\
        x;\
        t2 = clock();\
        long diff = (t2-t1)*1000000/CLOCKS_PER_SEC;\
        cout <<"time:\t" <<diff << endl;\
    }while(0)

class singleton{
 public:
    static singleton &get(){
        static singleton n;
        return n;
    }
    void profile_start(){
        t1 = clock();
    }
    void profile_stop(){
        t2 = clock();
        long diff1 = (t2-t1)*1000000/CLOCKS_PER_SEC;
        long diff2 = diff1/1000;
        std::cout << times++ << " takes " << diff1 << "us ("<<diff2<<" ms)\n";
    }
 private:
    singleton() {}
    clock_t t1, t2;
    int times;
};

void profile_start(){
    singleton::get().profile_start();
}

void profile_stop(){
    singleton::get().profile_stop();
}

#endif
