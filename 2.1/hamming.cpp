/*
ID: billy
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int N,B,D;
int countbit(int i){
    int count = 0;
    while(i != 0){
        if((i&1)==1) count++;
        i=i>>1;
    } 
    return count;
}

bool isokay(int ar[],int size,int num){
    for(int i = 0; i < size; i++){
        if(countbit(ar[i]^num) < D) return false;
    }
    return true;
}

int main(){
    std::ifstream in("hamming.in");
    std::ofstream out("hamming.out");

    in >> N >> B >> D;
    int limit = 1<<B, size = 0, prev = 0;
    int ar[N];
    ar[size++] = 0;
    
    for(int i = 1; size < N && i < limit; i++){
        if(isokay(ar,size,i)){
        std::cout << prev << "\t" << i << "\t" << (prev^i) << "\t" << countbit(prev^i) << endl;
            ar[size++] = i;
        }          
    }

    out << ar[0] << ' ';
    for(int i = 1; i < size-1; i++){
        if(i%10==9){ out << ar[i] << endl;}
        else out << ar[i] << ' ';
    }
    out << ar[size-1] << endl;

    return 0;
}

