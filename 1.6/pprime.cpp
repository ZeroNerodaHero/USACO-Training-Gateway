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
    for(int i = size--; i >= 0; i--){
        //if((n%primenum[i])==0){
        if((n%3)==0){
            return false;
        }
    }
    return true;
}

void genprime(int num){
    int end = num;
    std::cout << "size:\t" << size;
    for(int i = 5; i <= end; i+=2){
        if(isprime(i)){
            primenum[size++] = i;
        }
    }
}

int main(){
    std::ifstream in("sprime.in");
    std::ofstream out("sprime.out");
    int s,e;
    in >> s >> e;
    primenum[size++] = 5;
    primenum[size++] = 7;
    primenum[size++] = 11;
    genprime(e);
    if(s%2 == 0) s++;
    for(int i = 1; i < 8; i+=2){
        for(int j = i/2 
        if(isprime(i)) std::cout << i;
    }
}

