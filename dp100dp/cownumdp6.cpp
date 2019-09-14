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
unsigned int MM = 0x2FFFFFF;
unsigned int dp[2][1001][1001];
//unordered_map<int,int> m(100000);

void print(){
    for(int i = N; i >= 1; i--){
    for(int j = 1; j <= N; j++){
            cout << dp[1][j][i] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for(int i = N; i >= 1; i--){
    for(int j = 1; j <= N; j++){
            cout << dp[0][j][i] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int dfs(){
    for(int i = 1; i <= N; i++){
            dp[1][1][i] = i;
            dp[1][2][i] = i*i;
    }

    for(int i = 1; i <= N; i++){
            dp[0][1][i] = dp[1][1][i] + dp[0][1][i-1];
            dp[0][2][i] = dp[1][2][i] + dp[0][2][i-1];
    }
//print();

    int a = 0, b =1;
    for(int d = 3; d <= N; d++){
        //for(int i = d/2; i <= N-(N-d)/2; i++){
        for(int i = 1; i <= N; i++){
//            dp[b][d][i] 
//int kk = dp[b][d][i-1] + dp[b][d-1][i-1] + dp[b][d-2][i-1] + dp[a][d-2][i-2];
            dp[b][d][i] = dp[b][d][i-1] + dp[b][d-1][i-1] + dp[a][d-2][i-1];
//if(kk != dp[b][d][i]) cout << kk <<  " !=  " << dp[b][d][i] << endl;
            dp[a][d][i] = dp[b][d][i] + dp[a][d][i-1];
            if(dp[b][d][i] > MM) dp[b][d][i] %= MM;
            if(dp[a][d][i] > MM) dp[a][d][i] %= MM;
            //cout << d << ' ' <<  i << ' ' << dp[a][d][i] << ' ' << dp[b][d][i] << endl;
        }
    } 
    return (dp[b][N][N]%M);
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
//    print();
    
    out << ans << endl;
}
