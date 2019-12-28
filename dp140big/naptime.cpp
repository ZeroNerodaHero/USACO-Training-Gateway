/*
ID: billyz43
PROG: naptime
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
std::ifstream in("naptime.in");
std::ofstream out("naptime.out");
using namespace std;
int N,B;
int U[7680];
int dp[2][2][3835];

void print(int s){
    cout << "c " << s << endl;
    for(int a = 0; a < 2; a++){
        for(int i = 0; i < N; i++){
            for(int j = 1; j <= B; j++){
                cout.width(3);
                cout << dp[a][i][j];
            }
        cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}

int dfs(int s){
    int a = 0,b = 1;
    for(int i = 1; i < N; i++){
        for(int j = 2; j <= B; j++){
            dp[0][b][j] = max(dp[0][a][j],dp[1][a][j]);
            dp[1][b][j] = max(dp[0][a][j-1],dp[1][a][j-1] + U[i+s]); 
        }
        swap(a,b);
    }
    int ans = 0;
#if 0
    for(int j = 1; j <= B; j++){
        ans = max(ans,max(dp[0][N+s-1][j],dp[1][N+s-1][j]));
    }
#else
    ans = max(dp[0][a][B],dp[1][a][B]);
#endif
//    print(s);
    return ans;
}

int main(){
    in >> N >> B;
    for(int i = 0; i < N; i++){
        in >> U[i];
        U[i+N] = U[i]; 
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        memset(dp,0,sizeof(dp));
        ans = max(ans,dfs(i));
    }
    out << ans << endl;
}
