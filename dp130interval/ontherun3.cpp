/*
ID: billyz43
PROG: ontherun
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
#define INF 0x3f3f3f3f
std::ifstream in("ontherun.in");
std::ofstream out("ontherun.out");
using namespace std;
int N, L;
vector<int> ar;
int ans = INF;
int dp[2][1002][1002];
int sum[2][1002][1002];

int dfs(int b, int t,int i, int j){
    int l = (b == 0)? ar[i+1] : ar[j-1]; 
//    cout << i << ' ' << j << ' ' << t << " " << l <<endl;
    if(i == -1 && j == N) return t;
    if(i == -1){
        return dfs(1,t+ar[j]-l,i,j+1)+t;
    }
    if(j == N){
        return dfs(0,t+l-ar[i],i-1,j)+t;
    }
    
    if(t >= dp[b][i][j]) return INF;
    dp[b][i+1][j+1] = t;
    int ans = dfs(0,l-ar[i]+t,i-1,j)+t;
    ans = min(ans,dfs(1,ar[j]-l+t,i,j+1)+t);
    return ans;
}

int main(){
    in >> N >> L;
    ar.resize(N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        in >> ar[i];
        sum += ar[i];
    }   
    sort(ar.begin(),ar.end());
    auto st = lower_bound(ar.begin(),ar.end(),L);
    if(st == ar.end()){
        cout << sum << endl;
        return 0;
    }
    st--;
    int i = st-ar.begin();
    int j = i+1;
    cout << i << ' ' << j << endl;
    memset((&dp[0][0][0]),0x5F,sizeof(dp));
    int ans;
    if(i == -1) ans = dfs(1,ar[j]-L,i,j+1);
    else if(j == N) ans = dfs(0,L-ar[i],i-1,j);
    else{
        ans = min(dfs(0,L-ar[i],i-1,j), dfs(1,ar[j]-L,i,j+1));
    }
    out << ans << endl;
}
