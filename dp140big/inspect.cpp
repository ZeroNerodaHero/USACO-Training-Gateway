/*
ID: billyz43
PROG: inspect
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
std::ifstream in("inspect.in");
std::ofstream out("inspect.out");
using namespace std;

int N,P,K;
list<int> g[2501];
long long dp[2][2501];

void print(){
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= N; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

long long dfs(){
    long long ans = 0;
    dp[1][1] = 1;
    int a = 1, b = 0;
    for(int k = 2; k <= N; k++){
        for(int n = 1; n <= N; n++){
            dp[b][n] = 0;
            for(auto i : g[n]){
                dp[b][n] += dp[a][i]; 
            }
        }
        if(k > K) ans+= dp[b][N];
        swap(a,b);
    }
//print();
    return ans;
}

int main(){
    in >> N >> K >> P;
//cout << N << K << P << endl;
    for(int i = 0; i < P; i++){
        int a,b;
        in >> a >> b;
//cout << a << b << endl;
        g[b].push_back(a);
    }

    long long ans =  dfs();
    out << ans << endl;
}
