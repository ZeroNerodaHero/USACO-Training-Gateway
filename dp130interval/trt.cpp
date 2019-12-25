/*
ID: billyz43
PROG: trt
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
#include <climits>
#define INF 9999
std::ifstream in("trt.in");
std::ofstream out("trt.out");
using namespace std;

int N;
int trt[2001];
int dp[2][2005];

int dfs(){
    int x = 0, y = 1;
    for(int i = 0; i < N; i++){
        dp[x][i] = trt[i] * N;
    }
    for(int a = N-1; a > 0; a--){
        for(int i = 0, j = N-a; j < N; i++,j++){
            int l = N-a;
            dp[y][i] = max(dp[x][i+1]+a*trt[i],
                              dp[x][i] +a*trt[i+l]);
        }   
        swap(x,y);
    }
    return dp[x][0]; 
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >>trt[i];
    }
    int ans = dfs();
    out << ans << endl;
}
