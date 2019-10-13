/*
ID: billyz43
PROG: cfair
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
#define INF 160000
std::ifstream in("cfair.in");
std::ofstream out("cfair.out");
using namespace std;
int ans = 0;
int N;
int P[402];
int d[401][401];

void dfs(int p, int t, int v){
    if(ans < v) ans = v;

    for(int i = 1; i <= N; i++){
        if((p != i)  && t + d[p][i] <= P[i]){
            dfs(i,P[i],v+1);   
        }
    }
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        in >> P[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            in >> d[i][j];
        }
    }

    dfs(1,0,0);   
    dfs(1,P[1],1);   
    cout << ans << endl;
}
