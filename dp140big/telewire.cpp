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
int N,C,M[100000];
int D;
int a[100000];
int dp[2][100];   
int mm[101],mc[101];

void init(){
    for(int i = 1; i <= 100; i++){
        mm[i] = i*i;
        mc[i] = C*i;
    }
}

void init2(){
    D = sqrt(C)+1;
    for(int i = 0; i < N; i++){
        if(mm[M[i] - a[i]] > mc[M[i] - a[i]]){
            M[i] = min(M[i],a[i] + 8* D);
        }
    }    
}

int dfs(){
    init();
    init2();
    int c = 0, d =1;
    for(int i = a[0]; i <= M[0]; i++){
        dp[0][i] = mm[i-a[0]];
    }
    for(int i = 1; i < N; i++){
        for(int j = a[i]; j <= M[i]; j++){
            dp[d][j] = INT_MAX;
            int dh = mm[j-a[i]];
            for(int k = a[i-1]; k <= M[i-1]; k++){
                int adh = mc[abs(k-j)];
                dp[d][j] = min(dp[d][j],adh+dh+dp[c][k]);
            }
        }   
        c ^= 1;
        d ^= 1;
    }
    int ans = INT_MAX;
    for(int i = a[N-1]; i <= M[N-1]; i++){
        ans = min(ans,dp[c][i]);
    }
    return ans;
}

void rec(){
    for(int i = 0; i < N; i++){
        if(i > 0) M[i] = max(M[i],M[i-1]);
        if(i < N-1) M[i] = max(M[i],M[i+1]);
    }       
}

int main(){
    in >> N >> C;
    for(int i = 0; i < N; i++){
        in >> a[i];
    }
    for(int i = 0; i < N; i++){
        M[i] = a[i];
        if(i > 0) M[i] = max(M[i],a[i-1]);
        if(i < N-1) M[i] = max(M[i],a[i+1]);
    }
    rec();
    int ans = dfs();
    out << ans << endl;
}
