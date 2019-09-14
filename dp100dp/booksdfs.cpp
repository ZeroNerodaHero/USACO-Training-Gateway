/*
ID: billyz43
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
#define INF (1 << 63)
std::ifstream in("books.in");
std::ofstream out("books.out");
using namespace std;
int N,E;
int bk[205];
int ep[105];

long long dfs(int cb, int ce){
    cout << cb << ' ' << ce << ' ' << endl;
    if(cb == N) return 0;
    if(ce == E-1){
        long long t = 0;
        int cnt = 0;
        for(int i = cb; i < N; i++){
            t += bk[i] * ep[cnt++];
        }
        return t;
    }

    long long mx = INT_MAX;
    long long cm = 0;
    for(int i = 0; i+cb < N; i++){
        int cmx = cm + bk[cb+i] * ep[i];
        cm = cmx;
        cmx += dfs(cb + i+1, ce + 1); 
        if(mx > cmx) mx = cmx;
    }
//    cout << mx << endl;
    return mx;
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
    cout << ans << endl;
}
