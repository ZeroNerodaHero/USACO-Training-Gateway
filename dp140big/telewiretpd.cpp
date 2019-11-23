/*
ID: billyz43
PROG: telewire
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <list>
#include <cmath>
#define INF 0x3F3F3F3F
std::ifstream in("telewire.in");
std::ofstream out("telewire.out");
using namespace std;
int N,C,M;
int a[100000];
//int dp[1000000][100];   
int dp[10000][100];   

int dfs(int h, int c){
    if(dp[c][h] >= 0){
        return dp[c][h];
    }
    if(c == N) return 0;
    int ans = INT_MAX;

    for(int i = a[c]; i <= M; i++){
        int adh = (i-a[c]) * (i-a[c]);
        int cad = 0;
        if(c > 0){
            cad = C*abs(h-i);
        }
        ans = min(ans,adh+cad+dfs(i,c+1));
    }
    dp[c][h] = ans;
    return ans;
}

int main(){
    in >> N >> C;
    for(int i = 0; i < N; i++){
        in >> a[i];
        M = max(a[i],M);
    }
    memset(dp,-1,sizeof(dp));
    int ans = dfs(a[0],0);
    out << ans << endl;
}
