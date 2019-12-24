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
    bool operator <(const bale& o){
        return h < o.h;
    }
};
int N,B;
int h[250];
bale b[250];

int dfs(int l, int r, int d){
//    cout << l << ' '<< r << ' ' << d << endl;
    if(l > r) return 0;
    if(d == N) return 0;

    int ans = dfs(l,r,d+1);
    for(int i = l,j = l+b[d].w-1; j <= r; i++,j++){
        if((h[i] >= b[d].h) && (h[j] >= b[d].h)){
            ans = max(ans,dfs(j+1, r, d+1)+b[d].a+dfs(l, i-1, d+1));
        }
    }
    return ans;
}

int main(){
    in >> N >> B;
    for(int i = 0; i < N; i++){
        in >> b[i].w >> b[i].h;
        b[i].a = b[i].w * b[i].h;
    }
    for(int i = 0; i < B; i++){
        in >> h[i];
    }
    int ans = dfs(0,B-1,0);
    out << ans << endl;
}
