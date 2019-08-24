/*
ID: billy
PROG: bcatch
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
std::ifstream in("bcatch.in");
std::ofstream out("bcatch.out");
using namespace std;
int T,W,ind;
int ch[1001];
int dp[1002][32];

void print(){
    for(int i = 0; i < ind; i++){
        cout << ch[i] << endl;
    }
}

int dfs(int c, int w){
    if(dp[c][w] >= 0) return dp[c][w];
    if(c == ind){
        dp[c][w] = 0;
        return 0;
    }   
    int ans = 0;
    if(w == W){
        if((c&1) == (w&1)){
            ans = ch[c];
            c+= 2;
        } else{
            c++;
        }
        while(c < ind){
            ans += ch[c];
            c += 2;
        }
        dp[c][w] = ans;
        return ans;
    } 

    if((c&1) == (w&1)) ans = ch[c];
//    cout << c << ' ' << w << ' ' << ans << endl;
    dp[c][w] = ans + max(dfs(c+1,w),dfs(c+1,w+1));
    return dp[c][w];
}



int main(){
    in >> T >> W;
    int p;
    p = 1;
    for(int i = 0; i < T; i++){
        int tmp;
        in >> tmp;
        if(tmp == p) ch[ind]++;
        else{
            ch[++ind]++;
            p = tmp;
        }
    }
    ind++;
    //print(); 
    memset(dp,-1,sizeof(dp));
    out << dfs(0,0) << endl;
}
