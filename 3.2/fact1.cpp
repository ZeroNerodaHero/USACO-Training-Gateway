/*
ID: billyz43
PROG: fact4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("fact4.in");
std::ofstream out("fact4.out");

int val[10000];

int main(){
    int N;
    in >> N;

    int last = 1;
    int k = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= 10; j++,k++){
            switch(j){
                case 2:
                    last <<= 1;
                    break;
                case 4: 
                    last <<= 2;
                    break;
                case 8: 
                    last <<= 3;
                    break;
                case 5:
                case 10:
                    last *= k;
                    break;
                default:
                    last *= j;       
                    break;
            }
            while(last%10==0){
                last /= 10;
            }
            if(k == N){
                out << last%10 << endl;
                return 0;
            }
            if(last > 10000) last %= 10000;
        }
    }
    return 0;
}

