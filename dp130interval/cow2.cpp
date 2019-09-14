/*
ID: billyz43
PROG: cowq
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <cmath>
#define INF 9999
std::ifstream in("cowq.in");
std::ofstream out("cowq.out");
using namespace std;
int N, B, J;
double dp[101];
int ans;

void print(){
    for(int i = 0; i < N; i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
}

void dfs(){
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < N; i++){
        for(int k = 0; k < i; k++){
            dp[i] += dp[k] * dp[i-k-1];
        }
    } 
}

int main(){
    in >> N >> B >> J;
    cout << "N " << N << endl;
    dfs();
    print();
}
