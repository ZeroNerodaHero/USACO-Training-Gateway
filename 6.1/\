/*
ID: billyz43
PROG: cowxor
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("cowxor.in");
std::ofstream out("cowxor.out");
int N;
int pre[MAXN];

void big(){
    int large = 0, a = 0,b=1;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j <= N; j++){
            int cur = pre[i] ^ pre[j];
            if(cur > large || (cur == large && j <= b)){
                large = cur;
                a = i;
                b = j;
            }
        }
    }
    out << large << ' ' << a+1 << ' ' << b << endl;
}

int main(){
    in >> N >> pre[1];

    for(int i = 2; i <= N; i++){
        int a;
        in >> a;
//        cout << "a "<< a << ' ';
        pre[i] = pre[i-1]^a;
//        cout << pre[i] << endl;
    } 

    big();    
}
