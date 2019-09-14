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
int dp[2][1001][1001];
//unordered_map<int,int> m(100000);

int dfs(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[0][i][j] = 1;
        }       
    }

    int a = 0, b =1;
    for(int d = 0; d < N-2; d++){
        memset(dp[b],0,sizeof(dp[b]));
        for(int i = d/2+1; i <= N-(N-d-3)/2; i++){
            for(int  j = d/2+1; j <= N-(N-d-3)/2; j++){
                for(int k = max(d/2,1); k < j; k++){
                    dp[b][i][j] += dp[a][k][min(i,j)];
//                cout << d << " ***** " <<  i << ' ' << j << ' ' << k << ' ' << dp[b][i][j] << endl;
                }
                if(dp[b][i][j] > M) dp[b][i][j] %= M;
                cout << d << ' ' <<  i << ' ' << j << ' ' << dp[b][i][j] << endl;
            }



        }    
        swap(a,b);
    } 
    int ans = 0;
    for(int i = N/2; i <= N; i++){
        for(int j = N/2; j <= N; j++){
            ans += dp[a][i][j];
        }
    }
    return (ans%M);
}

int main(){
    in >> N >> M;
    if(M == 1){
        out << 0 << endl;
        return 0;
    }
    int ans = dfs();
    
    out << ans << endl;
}
