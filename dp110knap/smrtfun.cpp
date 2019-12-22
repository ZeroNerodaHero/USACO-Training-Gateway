/*
ID: billyz43
PROG: smrtfun
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
#define INF 0x1f1f1f1f 
std::ifstream in("smrtfun.in");
std::ofstream out("smrtfun.out");
using namespace std;
int N,M,l,r;
int s[101],f[101];
int res;
const int mask = (1<<11)-1;
int dp[200002];
const int mx = 100000;

int dfs(){
    memset(dp,0x1f,sizeof(dp));
    dp[mx] = 0;
    for(int i = 1; i < M; i++){
        if(s[i] >= 0){
        for(int j = r-s[i]+mx; j >= l+mx; j--){
            if(dp[j] != INF){
                if(dp[j+s[i]] == INF || dp[j+s[i]] < (dp[j] + f[i])){
                    dp[j+s[i]] = (dp[j] + f[i]);
                }
            }
        }
        } else{
            for(int j = l-s[i]+mx; j <= r+mx; j++){
                if(dp[j] != INF){
                    if(dp[j+s[i]] == INF || dp[j+s[i]] < (dp[j] + f[i])){
                        dp[j+s[i]] = (dp[j] + f[i]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = mx; i <= r+mx; i++){
        if(dp[i] != INF && dp[i] >= 0){
            ans = max(ans,i + dp[i]);
        }
    }
    return ans-mx;
}

int main(){
    in >> N;
    M=1;
    for(int i = 0; i < N; i++){
        in >> s[M] >> f[M];
        if(s[M] > 0 || f[M] > 0){
            r += max(0,s[M]);
            l += min(0,s[M]);
            M++;
        }
    }
    //l = min(l,0);
    cout << "M " <<M << endl;
    cout << "\t " <<r << ' ' << l << endl;
    res = dfs();
    out << res << endl;
}
