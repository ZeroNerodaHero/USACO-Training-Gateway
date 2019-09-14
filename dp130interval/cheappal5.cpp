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
int c1[128];
int dp[4][2000];

void print(int l){
    cout << l << '\t';
    for(int i = 0; i+l <M; i++){
        cout << dp[l][i] << ' ';
    } 
    cout << endl;
}

int dfs(){
    for(int i = 0; i < M-1; i++){
        if(s[i] != s[i+1]){
            dp[1][i] = min(c1[s[i]],c1[s[i+1]]);
        }
    }    

    int a = 0, b = 1, c = 2;
  //  print(b);
    for(int l = 2; l < M; l++){
        for(int i = 0; i+l < M; i++){
            int j = i+l;
            int ans = min(dp[b][i+1]+c1[s[i]],dp[b][i]+c1[s[j]]);
            if(s[i] == s[j]) ans = min(ans,dp[a][i+1]);
            dp[c][i] = ans;
        }
//        print(c);
        a++;
        b++;
        c++;
        a &= 3, b&=3, c&=3;
    }
//   cout << b << ' ' << dp[b][0] << endl;
    return dp[b][0];
}

int main(){
    in >> N >> M >>s;
//    cout << N << ' ' << M << endl;
    for(int i = 0; i < N; i++){
        char ccha;
        int ca,cd;
        in >> ccha >> ca >> cd;
        c1[ccha] = min(ca,cd);
    }
    //memset(&(dp[0][0]),-1,sizeof(dp));
    int ans = dfs();
    out << ans << endl;
}
