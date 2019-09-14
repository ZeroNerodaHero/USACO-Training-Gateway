/*
ID: billyz43
PROG: bigbrn
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
std::ifstream in("bigbrn.in");
std::ofstream out("bigbrn.out");
int N, big;
int dp[1001][1001];

void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
        cout << "end"<< endl;
}

void mxsq(){
    for(int j = 2; j <= N; j++){
        for(int i = N-1; i >= 0; i--){
            if(dp[i][j] == 0) continue;
            dp[i][j] = 1+min(dp[i+1][j],min(dp[i][j-1],dp[i+1][j-1]));
            big = max(big,dp[i][j]);
        }
    }
}

int main(){
    int T;
    in >> N >> T;
    if(T == N*N){
        out << 0 << endl;
        return 0;
    }
    big = 1;
    //memset(dp,1,sizeof(dp));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = 1;
        }
    }

    for(int i = 0; i < T; i++){
        int x,y;
        in >> x >> y;
     //   cout << x << ' ' << y << endl;
        dp[x][y] = 0;
    }
//    print();
    mxsq();
//    print();

    out << big << endl;
}
