/*
ID: billyz43
PROG: cowfact
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
#define MAXN 1030
std::ifstream in("cowfact.in");
std::ofstream out("cowfact.out");
using namespace std;
int N,K,M,R;
int c[100];
int p[100];
int dp[2][100001];

int dfs(){
    int a = 0, b = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= R; j++){
            if(j-c[i] < 0) dp[b][j] = dp[a][j];
            else dp[b][j] = max(dp[a][j],dp[a][j-c[i]]+p[i]);
        }
        swap(a,b);
    }

    int sc = INF;
    for(int i = 1; i <= R; i++){
//        cout << i << " " << dp[N][i] << endl;;
        if(dp[a][i] < K) continue;
        int as = (i*10000/dp[a][i]);
        sc = min(as,sc);
    }
    int ans = M * 10000 - sc; 
    ans/=10;    
    return max(ans,-1);
}

int main(){
    in >> N >> K >> M >> R;
    for(int i = 1; i <= N; i++){
        in >> c[i] >> p[i];
    }    
    int ans = dfs();
    out << ans << endl;
}
