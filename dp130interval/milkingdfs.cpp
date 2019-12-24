/*
ID: billyz43
PROG: milking
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
#include <climits>
#define INF 0x3f3f3f3f
std::ifstream in("milking.in");
std::ofstream out("milking.out");
using namespace std;

struct node{
    int p, t;
};

node ar[1005];
bool v[1005];
int C,P,H;
int dfs(int c, int t,int cnt){
    if(cnt == C){
        return t+abs(H-ar[c].p);
    } 
    v[c] = true;
    int ans = INF;
    for(int i = 1; i <= C; i++){
        if(!v[i]){
            int tt = max(ar[i].t,t+abs(ar[i].p-ar[c].p));
            ans = min(ans,dfs(i,tt,cnt+1));
        }
    }
    v[c] = false;;
    return ans;
}

int main(){
    in >> C >> P >> H;
    for(int i = 1; i <= C; i++){
        in >> ar[i].p >> ar[i].t;
    }
    int ans = dfs(0,0,0);
    out << ans << endl;
}
