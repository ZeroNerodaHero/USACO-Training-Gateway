/*
ID: billy
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
    for(int i = 1; i <= N; i++){
        last *= i;
        while(last%10 == 0){
            last/=10;
        }
        last %= 100000;
    }
    out << last%10 << endl;
}

