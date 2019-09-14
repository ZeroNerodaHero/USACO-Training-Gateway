/*
ID: billy
PROG: jpol
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
std::ifstream in("jpol.in");
std::ofstream out("jpol.out");
using namespace std;
int K, N;
int ans[3][61];
int c[182];

bool dfs(int c1, int c2,int c3, int v1,int v2, int v3, int i){
    if(i == K*3){
        int t = 0;
        if(v1 > N) t++;
        if(v2 > N) t++;
        if(v3 > N) t++;
        return t > 1;
    }
    if(c1 < K && dfs(c1+1,c2,c3,v1+c[i],v2,v3,i+1)){
        ans[0][c1] = i;
        return true;
    }
    if(c2 < K && dfs(c1,c2+1,c3,v1,v2+c[i],v3,i+1)){
        ans[1][c2] = i;
        return true;
    }
    if(c3 < K && dfs(c1,c2,c3+1,v1,v2,v3+c[i],i+1)){
        ans[2][c3] = i;
        return true;
    }
    return false;
}

int main(){
    in >> K;
    N = 500 * K;
    for(int i = 0; i < 3*K; i++){
        in >> c[i];
        cout << c[i] << ' ';
    }   
    cout << endl;
    dfs(0,0,0,0,0,0,0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < K; j++){
            out  << ans[i][j]+1 << endl;
        }
    }
}
