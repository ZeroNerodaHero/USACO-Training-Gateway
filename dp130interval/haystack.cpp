/*
ID: billyz43
PROG: haystack
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
std::ifstream in("haystack.in");
std::ofstream out("haystack.out");
using namespace std;

struct pt{
    int x,y;
    bool operator< (const pt& o) const{
        return x < o.x;
    }
};
int N;
pt p[205];
int dp[2][205][205];

int dist(int a, int b){
    return abs(p[a].x-p[b].x)+abs(p[a].y)+abs(p[b].y);
}

void dfs(){
    for(int i = 0; i < N; i++){
        dp[0][i][i+1] = dp[1][i][i+1] = dist(i,i+1);
    }
    for(int l = 2; l <= N; l++){
        for(int i = 0; i + l <= N; i++){
            int j = i+l;
            dp[0][i][j] = INT_MAX;
            for(int k = i+1; k <= j; k++){
                int big = max(dp[1][i+1][k], dp[0][k][j]);
                big += dist(i,k);
                dp[0][i][j] = min(dp[0][i][j],big);
            }
            dp[1][i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                int big = max(dp[1][i][k],dp[0][k][j-1]) + dist(j,k);
                dp[1][i][j] = min(dp[1][i][j],big);
            }
        } 
    }
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        in >> p[i].x >> p[i].y;
    }
    p[0].x = 0;
    p[0].y = 0;
    sort(p+1,p+N+1);
    dfs();

    out << dp[0][0][N] << endl;
}
