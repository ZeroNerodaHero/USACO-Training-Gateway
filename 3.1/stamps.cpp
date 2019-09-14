/*
ID: billyz43
PROG: stamps
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("stamps.in");
std::ofstream out("stamps.out");

int val[10000];

int main(){
    int K, N;
    in >> K >> N;
    for(int i = 0; i < N; i++){
        in >> val[i];
    }
    sort(val,val+N);
    int limit = val[N-1] * K + 10;
    int dp[limit];
    for(int i = 0; i < limit; i++){
        dp[i] = INF;
    }    
    dp[0] = 0;

    for(int i = 1; i < limit; i++){
        for(int j = 0; j < N; j++){
            if(i-val[j] < 0) break;
            dp[i] = min(dp[i],dp[i-val[j]]+1);
        }
        if(dp[i] > K){
            out << (i-1) << endl;
            break;
        }
    }
}

