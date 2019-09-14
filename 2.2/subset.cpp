/*
ID: billyz43
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("subset.in");
    std::ofstream out("subset.out");
    int N;
    in >> N;
    int total = 0,count = 0;
    for(int i = 0; i < N; i++){
        total += i;
    }
    for(int i = N-1; i > 0; i++){
        int total2 = 0;
        for(int j = i; j > 0; j++){
            if(total2 = total){
                count++;
            }
            
        }
    }
}


//generate a list
