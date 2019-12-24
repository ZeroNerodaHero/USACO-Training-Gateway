/*
ID: billyz43
PROG: milking
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
#define INF 0x3f3f3f3f
std::ifstream in("milking.in");
std::ofstream out("milking.out");
using namespace std;

struct node{
    int p, t;
    bool operator < (const node& o) const{
        if(p == o.p) return t < o.t;
        return p < o.p;
    }
};

node ar[1005];
bool v[1005];
int C,P,H;
int dp[2][1002][1002];
int dfs(){
    dp[0][0][C-1] = max(ar[0].p,ar[0].t);
    dp[1][0][C-1] = max(ar[C-1].p,ar[C-1].t);

    for(int l = C-2; l >= 0; l--){
        for(int i = 0, j = l; j < C; i++,j++){
            int a;
            dp[0][i][j] = INF;
            if(i > 0){
                a = max(dp[0][i-1][j] + abs(ar[i-1].p-ar[i].p),ar[i].t);
                dp[0][i][j] = min(dp[0][i][j],a);
            }
            if(j < C-1){
                a = max(dp[1][i][j+1] + abs(ar[j+1].p-ar[i].p),ar[i].t);
                dp[0][i][j] = min(dp[0][i][j],a);
            }

            a = INF;
            if(i > 0){
                a = max(dp[0][i-1][j] + abs(ar[i-1].p-ar[j].p),ar[j].t);   
            } 
            dp[1][i][j] = a;
            if(j < C-1){
                a = max(dp[1][i][j+1] + abs(ar[j+1].p-ar[j].p),ar[j].t);
            }
            dp[1][i][j] = min(dp[1][i][j],a);
        } 
    } 

    int ans = INF;
    for(int i = 0; i < C; i++){
        ans = min(ans,dp[0][i][i]+abs(ar[i].p-H));
    }
    return ans;
}

int main(){
    in >> C >> P >> H;
    for(int i = 0; i < C; i++){
        in >> ar[i].p >> ar[i].t;
    }
    sort(ar,ar+C);
    int ans = dfs();
    out << ans << endl;
}
