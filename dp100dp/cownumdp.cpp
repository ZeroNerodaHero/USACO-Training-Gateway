/*
ID: billyz43
PROG: cownum
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
#define INF 9999
std::ifstream in("cownum.in");
std::ofstream out("cownum.out");
using namespace std;
int N,M;
//int dp[3][998][1000];
int dp[998][1000];

int dfs(int d,int n1, int n2, int n3){
    if(d == -1){
//        print();
        return 1;
    }
    int ans = 0;
    int mx = min(n2,n3);
    mx -= 1;
#if 0
    int st = mx-n1 + 1;
    if((st >= 0 && st < 3) && dp[st][d][n1] >= 0) {
        return dp[st][d][n1];
    } 
#else
    if(mx==n1&&dp[d][n1] >= 0) {
        return dp[d][n1];
    }
#endif

    int i = d/2;
    if(i <= 0) i = 1;
//i=1;
    for(; i <= mx; i++){
        ans += dfs(d-1,i,n1,n2);
    }
    if(ans > M) ans %= M;
#if 0
    if(st >= 0 && st < 3){
        dp[st][d][n1]=ans;
    }
#else
    if(mx == n1) dp[d][n1] = ans;
#endif
//    cout << d << ": " << n1 << ": " << min(n2,n3) << ": " << ans  << ": " << n2 << ": " << n3 <<endl;
    return ans;
}

int main(){
    in >> N >> M;
    int ans = 0;
    memset(dp,-1,sizeof(dp));
    for(int i = N/2; i <= N; i++){
        for(int j = N/2; j <= N; j++){
            ans += dfs(N-3,i,j,INF);
        }
    }

    ans %= M;
    out << ans << endl;
}
