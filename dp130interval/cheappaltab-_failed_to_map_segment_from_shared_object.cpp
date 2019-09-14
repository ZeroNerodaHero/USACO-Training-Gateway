/*
ID: billyz43
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

void dfs(){
    for(int i = 0; i < M-1; i++){
        if(s[i] != s[i+1]){
            dp[i][i+1] = min(c[s[i]],c[s[i+1]]);
        }
    }    

    for(int l = 2; l < M; l++){
        for(int i = 0; i+l < M; i++){
            int j = i+l;
            int ans = min(dp[i+1][j]+c[s[i]],dp[i][j-1]+c[s[j]]);
            if(s[i] == s[j]) ans = min(ans,dp[i+1][j-1]);
            dp[i][j] = ans;
        }
    }
}

int main(){
    in >> N >> M >>s;
//    cout << N << ' ' << M << endl;
    for(int i = 0; i < N; i++){
        char ccha;
        int ca,cd;
        in >> ccha >> ca >> cd;
        c[ccha] = min(ca,cd);
    }
    //memset(&(dp[0][0]),-1,sizeof(dp));
    dfs();
    out << dp[0][M-1] << endl;
}
