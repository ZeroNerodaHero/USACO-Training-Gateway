/*
ID: billyz43
PROG: cowfood
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
#define INF (1<<28)
std::ifstream in("cowfood.in");
std::ofstream out("cowfood.out");
using namespace std;
bool m[14][14];
int N,M;
unordered_map<int,int> dp[14];

void dfs(int r, int c, int o, int n){
    int b = 1 << c;
    
    if(c == N){
        dp[r][n] += dp[r-1][o];
        if(dp[r][n] >= 100000000) dp[r][n] %= 100000000;
        return;
    }

    if(m[r][c] && ((o&(b))==0) && !(n&(b>>1))){
        dfs(r,c+1,o,n|b);
    } 
    dfs(r,c+1,o,n);
}

void print(int r){
    cout << "ROW " << r << endl;
    for(auto i: dp[r]){
        cout << i.first << ' ' << i.second << endl;
    }
    cout << endl;
}

int main(){
    in >> M >> N;

    for(int  i = 1; i <= M; i++){
        for(int j = 0; j < N; j++){
            in >> m[i][j];
        } 
    }
    
    dp[0][0] = 1;

    for(int i = 1; i <= M; i++){
        for(auto& j: dp[i-1]){
            dfs(i,0,j.first,0);
        }
//        print(i);
    } 
    
    int ans = 0;
    for(auto& i: dp[M]){
        ans += i.second;
        if(ans >= 100000000) ans %= 100000000;
    }
    out << ans << endl;
}
