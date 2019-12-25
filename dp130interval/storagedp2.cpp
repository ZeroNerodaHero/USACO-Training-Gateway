/*
ID: billyz43
PROG: storage
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
std::ifstream in("storage.in");
std::ofstream out("storage.out");
using namespace std;

struct bale{
    int w,h,a;
    int s,e;
    bool operator < (const bale& o) const{
        return h < o.h;
    }
};
int N,B;
int h[250];
bale b[251];
int dp[2][250][250];

int dfs(){
    int x=0,y=1;
    memset(dp,-1,sizeof(dp));
    dp[0][0][B-1] = 0;
    //int a = 0, c = 1;
    int a = 0, c = 0;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        memset(dp[y],-1,sizeof(dp[y]));
        for(int w = 0; w < B; w++){
            for(int l = 0, r = w; r < B; l++,r++){
                if(dp[x][l][r] == -1){
                    continue;
                }
                dp[y][l][r] = dp[x][l][r];
                if((w+1)>= b[i].w){
                    for(int s=l, e = l + b[i].w-1; e <= r; s++,e++){
                        if(b[i].h <= h[s] && (b[i].h <= h[e])){ 
                                if((e+1) > r){
                                   ans = max(ans,dp[x][l][r] + b[i].a);
//cout << "l ans " <<  ans << endl;
                                } else {
                                dp[y][e+1][r] = max(dp[y][e+1][r],
                                                max(dp[x][e+1][r],dp[x][l][r] + b[i].a)); 
//cout << "l dp[y][e+1][r] " <<  dp[y][e+1][r] << endl;
}
                            break;
                        }
                    }
                    for(int s = r-b[i].w+1,e=r; s >= l; s--,e--){
                        if(b[i].h <= h[e] && b[i].h <= h[s]){
                                if((s-1) < l){
                                    ans = max(dp[x][l][r] + b[i].a,ans);
//cout << "r ans " <<  ans << endl;
                                    break;
                                }
                                dp[y][l][s-1] = max(dp[y][l][s-1],
                                                max(dp[x][l][s-1],dp[x][l][r] + b[i].a)); 
//cout << "r dp[y][l][s-1] " <<  dp[y][l][s-1] << endl;
                            break;
                        }
                    }
                }
            }
        }       
        swap(x,y);
#if 0
        for(int a = 0; a < B; a++){
            for(int c = 0; c < B; c++){
                cout << dp[i][a][c] << ' ';
            }
            cout << endl;
        }
        cout << ans << endl;;
        cout << endl;
#endif
    }
        for(int a = 0; a < B; a++){
            for(int b = a; b < B; b++){
                ans = max(ans,dp[x][a][b]);
            }
        }
    return ans;
}

int main(){
    in >> N >> B;
    for(int i = 1; i <= N; i++){
        in >> b[i].w >> b[i].h;
        b[i].a = b[i].w * b[i].h;
    }
    for(int i = 0; i < B; i++){
        in >> h[i];
    }
    sort(b,b+N);
    int ans = dfs();
    out << ans << endl;
}
