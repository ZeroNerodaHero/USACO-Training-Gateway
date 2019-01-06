/*
ID: billy
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
std::ifstream in("money.in");
std::ofstream out("money.out");
int coins[25];
int V,N;    

int ways(int total){
    int dp[25][10000];
    for(int i = 0; i < V; i++){
        dp[i][0] = 1;
    }
    for(int i = 0; i < total; i++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= N; j++){
            if(j-coins[i] < 0) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
        }
    }
    return dp[V][N];
}

long long dp[10005];
void print(int total){
    for(int i = 0; i <= total; i++){
        std::cout << dp[i] << ' ';
    } cout << endl;
}
int ways1(int total, int c){
    if(total < 0) return 0;
    if(total == 0) return 1;
    dp[total] += ways1(total-c, c);
    return dp[total];
}

int ways1(int total)
{
    int sum =0;
    for(int i = 0; i < V; i++){
        sum += ways1(total,coins[i]);
    }
    print(total);
    return sum;
}


long long waydp(int total){
    dp[0] = 1;
    for(int i = 0; i < V; i++){
        for(int j = coins[i]; j <= total; j++){
            dp[j] += dp[j-coins[i]]; 
        }   
    //print(total);
    }
    return dp[total];
}

int main(){
    in >> V >> N;
    std::cout << V << ' ' << N << endl;
    for(int i = 0; i < V; i++){
        in >> coins[i];
    }
    std::sort(coins,coins+V, std::greater<int>());
    out << waydp(N) << endl;;
    //std::cout << ways1(N) << endl;
    //std::cout << waydp(2) << endl;
    //std::cout << waydp(3) << endl;
}
