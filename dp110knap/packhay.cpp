/*
ID: billyz43
PROG: packhay
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
std::ifstream in("packhay.in");
std::ofstream out("packhay.out");
using namespace std;
int M, H;
int b[200];
bool dp[201][5001];

void dfs(){
    dp[0][0] = true;
    for(int i = 1; i <= H; i++){
        dp[i][0] = true;
        for(int j = 1; j <= M; j++){
            if(b[i-1] <= j){
                dp[i][j] = dp[i-1][j-b[i-1]];
            }
            dp[i][j] |= dp[i-1][j];
        }
    }
}

int main(){
    in >> M >> H;
    for(int i = 0; i < H; i++){
        in >> b[i];
    }
    dfs();
    for(int i = M; i >= 0; i--){
        if(dp[H][i]){
            out << i << endl;
            break;
        }
    } 
}
