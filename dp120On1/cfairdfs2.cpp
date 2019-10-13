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

int dfs(int p){
    int mv = 0;
    for(int i = 1; i <= N; i++){
        if(i != p && P[p] + d[p][i] <= P[i]){
            mv = max(mv,dfs(i)+1);   
        }
    }
    return mv;
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
    for(int i = 1; i <= N; i++){
        d[0][i] = d[1][i];
    }

    int ans = dfs(0);   
    out << ans << endl;
}
