/*
ID: billyz43
PROG: inspect
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
std::ifstream in("inspect.in");
std::ofstream out("inspect.out");
using namespace std;

int N,P,K;
list<int> g[2501];
int dp[2501][2501];

int dfs(int pos, int cnt){
    cout << pos <<" " << cnt << " " <<  dp[pos][cnt]  << endl;
    if(dp[pos][cnt] != -1) return dp[pos][cnt];
    if(pos == N){
        if(cnt >= K) return 1;
        else return 0;
    }
    int pa = 0;
    for(auto i: g[pos]){
        pa += dfs(i,cnt+1);
    }
    dp[pos][cnt] = pa;
    return pa;

}

int main(){
    in >> N >> K >> P;
    cout << N << K << P << endl;
    for(int i = 0; i < P; i++){
        int a,b;
        in >> a >> b;
    cout << a << b << endl;
        g[a].push_back(b);
    }

    memset(dp,-1,sizeof(dp));
    int ans =  dfs(1,0);
    out << ans << endl;
}
