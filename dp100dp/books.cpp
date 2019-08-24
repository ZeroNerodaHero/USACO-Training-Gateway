/*
ID: billy
PROG: books
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
const long long  INF = 1LL << 62;
std::ifstream in("books.in");
std::ofstream out("books.out");
using namespace std;
int N,E;
long long bk[205];
long long ep[205];
long long dp[201][101];

long long dfs(int cb, int ce){
//    cout << "dfs " << cb << ' ' << ce << ' ' <<  dp[cb][ce] << endl;
    if(dp[cb][ce] > 0) return dp[cb][ce];
    if(cb == N) return 0;
    if(ce == E-1){
        long long t = 0;
        int cnt = 0;
        for(int i = cb; i < N; i++){
            t += bk[i] * ep[cnt++];
        }
        return t;
    }

    long long mx = INF;
    long long cm = 0;
    for(int i = 0; i+cb < N; i++){
        long long cmx = cm + bk[cb+i] * ep[i];
        cm = cmx;
        cmx += dfs(cb + i+1, ce + 1); 
//        cout << mx << ' ' << cmx << ' ' << cm  <<endl;
        if(mx > cmx) mx = cmx;
    }
    //cout << mx << endl;
    dp[cb][ce] = mx;
    return mx;
}

void print(){
    cout << N << ' ' <<  E << '\t';
    cout << "-----------------------\n";
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 100; j++){
            cout << dp[i][j] << ' ';
      }
        cout << endl;
    }
}

int main(){
    in >> N >> E;
    for(int i = 0; i < N; i++){
        in >> bk[i];
    }   
    for(int i = 0; i < N; i++){
        in >> ep[i];
    }
    long long ans = dfs(0,0);
    out << ans << endl;
}
