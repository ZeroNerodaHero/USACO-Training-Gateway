/*
ID: billy
PROG: ontherun
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
#define INF 9999
std::ifstream in("ontherun.in");
std::ofstream out("ontherun.out");
using namespace std;
int N, L;
int ar[1001];
bool v[1001];
int ans = INT_MAX;

void dfs(int p, int t, int st, int d){
    if(d == N){
        ans = min(ans,st);
        return;
    }
    for(int i = 0; i < N; i++){
        if(v[i]) continue;
        v[i] = true;
        int dif = t+abs(p-ar[i]);
        dfs(ar[i],dif,st+dif,d+1);
    cout << p << ' ' << d << ' ' << dif << endl;
        v[i] = false;
    }
}

int main(){
    in >> N >> L;
    for(int i = 0; i < N; i++){
        in >> ar[i];
    }   
    dfs(L,0,0,0);
    cout << ans << endl;
}
