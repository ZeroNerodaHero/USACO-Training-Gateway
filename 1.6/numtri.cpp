/*
ID: NomNom
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int R;
int v[1000][1002];
int dp[1000][1002];

int dfs(){
    dp[0][1] = v[0][1];
    for(int i = 1; i < R; i++){
        for(int j = 1; j <= i+1; j++){
            dp[i][j] = v[i][j] + std::max(dp[i-1][j-1],dp[i-1][j]); 
        }
    }
    int big = dp[R-1][1];
    for(int j = 2; j <= R; j++){
        big = max(big,dp[R-1][j]);
    }  
    return big;
}

int main(){
    std::ifstream in("numtri.in");
    std::ofstream out("numtri.out");
    in >> R;
    for(int i = 0; i < R; i++){
        for(int j = 1; j <= i+1; j++){
            in >> v[i][j];
        }
    }
    out << dfs()<<endl;
    return 0;      
}

