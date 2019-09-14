/*
ID: billyz43
PROG: inflate
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
std::ifstream in("inflate.in");
std::ofstream out("inflate.out");

struct test{
    int pt, min;
    test(int pt, int min): pt(pt), min(min) {}
    test() {}
};

int dp[10001];

int main(){
    int M, N;
    in >> M >> N;
    test ar[N];
    for(int i = 0; i < N; i++){
        int t1,t2;
        in >> t1 >> t2;
        ar[i] = test(t1,t2);
    }
    dp[0] = 0;

    for(int i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            if(i < ar[j].min) continue;
            dp[i] = max(dp[i],dp[i-ar[j].min]+ar[j].pt);
        }
    }

    out << dp[M] << endl;
}

