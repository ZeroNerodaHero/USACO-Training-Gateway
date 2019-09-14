/*
ID: billyz43
PROG: pie1
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
std::ifstream in("pie1.in");
std::ofstream out("pie1.out");
using namespace std;
int R, C;
int g[102][102];
int dp[102][102];

void pie(){
    dp[1][1] = g[1][1];
    for(int i = 2; i<= C; i++){
        for(int j = max(i+R-C,1); j <= min(i,R); j++){
    //        cout << i << ' ' << j << endl;
            dp[i][j] = dp[i-1][j];
            dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
            dp[i][j] += g[i][j];
        }
    }
    out << dp[C][R] << endl;
}

int main(){
    in >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            in >> g[j][i];
        }
    }
    pie();
    
}
