/*
ID: billyz43
PROG: packhay
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
std::ifstream in("packhay.in");
std::ofstream out("packhay.out");
using namespace std;
int M, H, ans = 0;
int b[200];

void dfs(int i, int t){
    if(i == H){
        ans = max(ans,t);   
        return;
    }
    if(t+b[i] <= M) dfs(i+1,t+b[i]);
    dfs(i+1,t);
}

int main(){
    in >> M >> H;
    for(int i = 0; i < H; i++){
        in >> b[i];
    }
    dfs(0,0);
    cout << ans << endl;
}
