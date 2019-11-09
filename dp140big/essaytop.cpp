/*
ID: billyz43
PROG: essay
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
std::ifstream in("essay.in");
std::ofstream out("essay.out");
using namespace std;
int S,Q;
int w[1000];
int q[1000];
short dp[1002][5000];

void print(){
    for(int i = 0; i <= S; i++){
        for(int j = 0; j <= Q; j++){
            if(dp[i][j] < 0){
                cout << "| ";
                //cout << dp[i][j] << ' ';
            } else{
                cout << dp[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

short dfs(int t, int tq){
    if(t == S) return 0;
    if(dp[t][tq] >= 0){
        return dp[t][tq];
    }
    int waitq = max(tq - q[t],0);
    int ret = dfs(t+1,waitq);
    if(tq+w[t] <= Q){
        ret = max(ret,dfs(t+1,tq+w[t]) + 1);
    }
    dp[t][tq] = ret;
    return ret;
}

int main(){
    in >> S >> Q;
    for(int i = 0; i < S; i++){
        in >> w[i] >> q[i];
    }
    memset(dp,-1,sizeof(dp));
    int ans =dfs(0,0);
    print();
    out << ans << endl;
}
