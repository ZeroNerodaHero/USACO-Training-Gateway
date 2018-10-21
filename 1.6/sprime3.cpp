/*
ID: billy
PROB: sprime
LANG: C++11
*/
#include <iostream>
#include <math.h>
#include <fstream>
#include <time.h>
    std::ifstream in("sprime.in");
    std::ofstream out("sprime.out");
using namespace std;
int prime[4] = {2,3,5,7};
int odd[4] = {1,3,7,9};

#define PROFILE(x)\
    do{\
        clock_t t1, t2;\
        t1 = clock();\
        x;\
        t2 = clock();\
        long diff = (t2-t1)*1000000/CLOCKS_PER_SEC;\
        cout <<"time:\t" <<diff << endl;\
    }while(0)

bool isprime(int n){
    int y = sqrt(n);
    for(int i = 3; i <= y; i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}

void dfs(int n, int level){
    if(level == 1){
        out << n << std::endl;;
        return;
    }   
    for(int i = 0; i < 4; i++){
        int m = (n*10)+odd[i];
        if(isprime(m)){
            dfs(m,level-1);
        }
    }
}

int main(){
    int N;
    in >> N;
    std::cout << N << std::endl;
    for(int i = 0; i < 4; i++){
       PROFILE(dfs(prime[i],N));
    }
    return 0;
}

