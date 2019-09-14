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
unsigned int MM = 0x7FFFFFFF;
unsigned int dp[2][1001][1001];
//unordered_map<int,int> m(100000);

int dfs(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[0][i][j] = 1;
        }       
    }

    for(int j = 1; j <= N; j++){
        for(int i = 1; i <= N; i++){
            dp[0][i][j] += dp[0][i-1][j];
//            cout << i << ' ' << j << ' ' << dp[0][i][j] << endl;
        }

    }
//    cout << endl;

    int a = 0, b =1;
    for(int d = 3; d <= N; d++){
        memset(dp[b],0,sizeof(dp[b]));
        for(int i = d/2; i <= N-(N-d)/2; i++){
            for(int  j = d/2; j <= N-(N-d)/2; j++){
                dp[b][i][j] += dp[a][j-1][min(i,j)];
//                if(dp[b][i][j] > M) dp[b][i][j] -= M;
//                cout << d << ' ' <<  i << ' ' << j << ' ' << dp[b][i][j] << endl;
            }
        } 

        for(int j = d/2; j <= N-(N-d)/2; j++) {
            for(int k = d/2; k <= N-(N-d)/2; k++) {
                dp[b][k][j] += dp[b][k-1][j];
                if(dp[b][k][j] > MM) dp[b][k][j] -= MM;
            }

        }    
#if 0
            for(int  j = d/2+1; j <= N-(N-d-3)/2; j++){
        for(int i = d/2+1; i <= N-(N-d-3)/2; i++){
                cout << " ** " <<  i << ' ' << j << ' ' << dp[b][i][j] << endl;
            }
        }
#endif
        swap(a,b);
    }
    unsigned int ans = 0;
    for(int j = N/2; j <= N; j++){
        ans += dp[a][N][j];
        if (ans > MM) ans -= MM;
    }
    return (ans%M);
}

int main(){
    in >> N >> M;
    if(M == 1){
        out << 0 << endl;
        return 0;
    }

    MM = (MM/M)*M;
//    cout << MM << endl;
    int ans = dfs();
    
    out << ans << endl;
}
