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

void dfs(int i, int sp, int sc){
    if(i == N){
        if(sp < K || sc > R) return;
        int pr = M * sp - sc;
        int ef = M*10000 - (sc*10000/sp);
        ef /= 10;
        ans = max(ef,ans); 
        return;
    }

    dfs(i+1,sp+p[i],sc+c[i]);   
    dfs(i+1,sp,sc);   
}

int main(){
    in >> N >> K >> M >> R;
    for(int i = 0; i < N; i++){
        in >> c[i] >> p[i];
    }    
    dfs(0,0,0);
    cout << ans << endl;
}
