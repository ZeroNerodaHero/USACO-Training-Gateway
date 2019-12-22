/*
ID: billyz43
PROG: cowfact
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
#define INF (1<<28)
#define MAXN 1030
std::ifstream in("cowfact.in");
std::ofstream out("cowfact.out");
using namespace std;
int N,K,M,R,ans = -1;
int c[100];
int p[100];

int dfs(int i, int sp, int sc){
    if(i == N){
        if(sp < K || sc > R) return INF;
        int ef = (sc/sp);
        return ef;
    }

    return min(dfs(i+1,sp+p[i],sc+c[i]), dfs(i+1,sp,sc));   
}

int main(){
    in >> N >> K >> M >> R;
    R *= 10000;
    for(int i = 0; i < N; i++){
        in >> c[i] >> p[i];
        c[i] *= 10000;
    }    
    ans = M * 10000 - dfs(0,0,0);
    ans /= 10;
    if(ans < 0) ans = -1;
    cout << ans << endl;
}
