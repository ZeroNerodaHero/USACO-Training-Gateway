/*
ID: billy
PROG: elite
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("elite.in");
std::ofstream out("elite.out");
using namespace std;
int ar[101];
int N, S;

int dp[2][26][10000];

int sol(){
    dp[0][0][0] = 1;
    int a = 0,b = 1;
    for(int i = 1; i < 100; i++){
        memset(dp[b],0,sizeof(dp[b]));
        dp[b][0][0] = 1;
        for(int s = 1; s < S; s++){
            for(int k = 1; k <= N; k++){
                dp[b][k][s] += dp[a][k][s];
                if(s >= ar[i]) dp[b][k][s] += dp[a][k-1][s-ar[i]];
            }
        }
        a ^= 1;
        b ^= 1;
    } 
    int ans = 0;
    for(int s = 1; s < S; s++){
        ans += dp[a][N][s];
    }
    return ans;
}


int main(){
    in >> N >> S;
    for(int i = 1; i <= 100; i++){
        ar[i] = i * i;
    }

    int ans = sol();
    out << ans << endl;
}
