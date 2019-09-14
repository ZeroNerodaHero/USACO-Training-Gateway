/*
ID: billyz43
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
int primenum[100000];
int size = 0;
bool isprime(int n){
    for(int i = size-1; i >= 0; i--){
        if((n%primenum[i])==0){
            return false;
        }
    }
    return true;
}

void genprime(int num){
    int end = sqrt(num);
    primenum[size++] = 3;
    for(int i = 5; i <= end; i+=2){
        if(isprime(i)){
            primenum[size++] = i;
        }
    }
}

int main(){
    std::ifstream in("sprime.in");
    std::ofstream out("sprime.out");
    int R;
    in >> R;
    std::cout << R << std::endl;
    int end, start =1;
    while(R > 1){
        start *= 10;
        R--;
    }
    std::cout << start << std::endl;
    end = start*10;
    std::cout << end << std::endl;
    genprime(end);
    for(int i = 0; i < 10; i++){
        std::cout << primenum[i] << ' ';
    }
    
    for(start++; start<end; start+=2){
        if(start%10==5) continue;
        if(isprime(start)){
            std::cout << start << endl;
        }
    }
}

