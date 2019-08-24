/*
ID: billy
PROG: cheappal
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <climits>
#define INF 9999
std::ifstream in("cheappal.in");
std::ofstream out("cheappal.out");
using namespace std;

int N, M;
//string s;
char s[2001];
int c[128];
int dp[2000][2000];

int dfs(int i, int j){
//    cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
    if(dp[i][j] >= 0) return dp[i][j];
    if(i >= j){
        return 0;
    }
    int ans = dfs(i+1,j)+c[s[i]];
    ans = min(ans,dfs(i,j-1)+c[s[j]]);
    if(s[i] == s[j]){
        ans = min(ans,dfs(i+1,j-1));
    }
    dp[i][j] = ans;
    return ans; 
}

int main(){
    in >> N >> M >>s;
    for(int i = 0; i < N; i++){
        char ccha;
        int ca,cd;
        in >> ccha >> ca >> cd;
        c[ccha] = min(ca,cd);
    }
    memset(&(dp[0][0]),-1,sizeof(dp));
    int ans = dfs(0,M-1);
    out << ans << endl;
}
