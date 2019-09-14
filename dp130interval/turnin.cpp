/*
ID: billyz43
PROG: turnin
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
#define INF 9999
std::ifstream in("turnin.in");
std::ofstream out("turnin.out");
using namespace std;

struct hw{
    int p,t;
    hw(int p, int t): p(p),t(t) {};
    hw() {};
    bool operator< (const hw& o) const{
        if(p < o.p) return true;
        if(p == o.p && t > o.t) return true;
        return false;
    }
};
int C,H,B,ans= INT_MAX;
hw cl[1001];
int dp[2][1001][1001];

void print(){
    for(int i = 0; i < C; i++){
        cout << cl[i].p << ' ' << cl[i].t <<  endl;;
    }
}

int dfs(){
    dp[0][0][C-1] = max(cl[0].t,cl[0].p);
    dp[1][0][C-1] = max(cl[C-1].t,cl[C-1].p);

    for(int l = C-2; l >= 0; l--){
        for(int i = 0; i < C-l; i++){
            int j = i+l;
            dp[0][i][j] = INT_MAX;
            dp[1][i][j] = INT_MAX;
            int tot;
            if(i > 0){
                tot = dp[0][i-1][j] + cl[i].p-cl[i-1].p;
                if(tot < cl[i].t) tot = cl[i].t;
                dp[0][i][j] = min(dp[0][i][j],tot);

                tot = dp[0][i-1][j] + cl[j].p-cl[i-1].p;
                if(tot < cl[j].t) tot = cl[j].t;
                dp[1][i][j] = min(dp[1][i][j],tot);
            }
            if(j < C-1){
                tot = dp[1][i][j+1] + cl[j+1].p - cl[i].p;
                if(tot < cl[i].t) tot = cl[i].t;
                if(dp[0][i][j] > tot) dp[0][i][j] = tot;
            
                tot = dp[1][i][j+1] + cl[j+1].p - cl[j].p;
                if(tot < cl[j].t) tot = cl[j].t;
                if(dp[1][i][j] > tot) dp[1][i][j] = tot;
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < C; i++){
        ans = min(ans,min(dp[0][i][i],dp[1][i][i]) + abs(B-cl[i].p));
    }
    return ans;
}

int main(){
    in >> C >> H >> B;
    for(int i = 0; i < C; i++){
        int a,b;
        in >> a >> b;
        cl[i] = hw(a,b);
    }
    sort(cl,cl+C);
//    print();
    
    int ans = dfs();
    out << ans << endl;
}
