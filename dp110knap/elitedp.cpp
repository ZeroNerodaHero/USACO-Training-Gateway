/*
ID: billy
PROG: elite
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
#define INF 9999
std::ifstream in("elite.in");
std::ofstream out("elite.out");
using namespace std;
int ar[101];
int N, S;

int dp[26][100][10000];

int sol(){
    dp[0][0][0] = 1;
    int a = 0,b = 1;
    for(int i = 1; i < 100; i++){
        dp[0][i][0] = 1;
        for(int s = 1; s < S; s++){
            for(int k = 1; k <= N; k++){
                dp[k][i][s] += dp[k][i-1][s];
                if(s >= ar[i]) dp[k][i][s] += dp[k-1][i-1][s-ar[i]];
            }
        }
    } 
    int ans = 0;
    for(int s = 1; s < S; s++){
        ans += dp[N][99][s];
    }
    return ans;
}


int main(){
    in >> N >> S;
    for(int i = 1; i <= 100; i++){
        ar[i] = i * i;
    }

    int ans = sol();
    out << ans << endl;
}
