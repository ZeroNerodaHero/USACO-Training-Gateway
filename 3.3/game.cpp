/*
ID: billyz43
PROG: game1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <algorithm>
#include <map>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("game1.in");
std::ofstream out("game1.out");

int dp[100][100];
int ar[100];

int main(){
    int N,sum = 0;
    in >> N;

    for(int i = 0; i < N; i++){
        in >> ar[i];
        sum += ar[i];
    }
    
    for(int i = 0; i < N; i++){
        dp[i][i] = ar[i];
    }

    for(int i = 0; i < N-1; i++){
        dp[i][i+1] = max(ar[i],ar[i+1]);
    }

    for(int l = 2; l < N; l++){
        for(int i = 0,j=l; j < N; i++,j++){
            dp[i][j] = max(ar[i] + min(dp[i+1][j-1],dp[i+2][j]),
                           ar[j] + min(dp[i+1][j-1],dp[i][j-2]));
        }
    }
    out << dp[0][N-1] << ' ' << sum-dp[0][N-1] << endl;
    return 0;
}
