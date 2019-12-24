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
int dp[100][250][250];

int dfs(){
    int a = 0, c = 0;
    for(int i = 1; i <= N; i++){
        for(int l = 0; l<B; l++){
            for(int r = l; r < B; r++){
                dp[c][l][r] = dp[a][l][r];
                if(r-l+1 >= b[i].w){
//cout << i << ' ' << endl;
                    for(int e = l,f=l+b[i].w-1; f <= r; e++,f++){
                        if(h[e] >= b[i].h && h[f] >= b[i].h){
                            int tmp = b[i].a;
                            if(e-1 >= l) tmp += dp[a][l][e-1];
                            if(f+1 <= r) tmp += dp[a][f+1][r];
                            dp[c][l][r] = max(dp[c][l][r],tmp);
                        }
                    }
                }
            }
        }
        a++,c++;//swap(a,c);
    }       
    int ans = 0;
    for(int l = 0; l < B; l++){
        for(int r = l; r < B; r++){
            ans = max(ans,dp[a][l][r]);
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
