/*
ID: billy
PROG: money2
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
std::ifstream in("money2.in");
std::ofstream out("money2.out");
using namespace std;
int V,N;
int cs[26];
long long dp[26][10005];

void print(){
    for(int i = 0; i <= V; i++){
        for(int j = 0; j <= min(N,20); j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve(){
    for(int i = 0; i <= V; i++){
        dp[i][0] = 1;
    }      

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= cs[i]) dp[i][j] += dp[i][j-cs[i]];
        }
    }
}

int main(){
    in >> V >> N;
    for(int i = 1; i <= V; i++){
        in >> cs[i];
    } 
    solve();
//    print();
    out << dp[V][N] << endl;
}
