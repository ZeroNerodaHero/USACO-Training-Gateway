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
bale b[250];
int ans = 0;
void dfs(int l, int r, int d,int a){
//    cout << l << ' '<< r << ' ' << d << ' ' << a <<endl;
    if(l > r){
        ans = max(ans,a);
        return;
    }
    if(d == N){
//        cout << "\t" << a << endl;
        ans = max(ans,a);
        return;
    }

    dfs(l,r,d+1,a);
    for(int i = l,j = l+b[d].w-1; j <= r; i++,j++){
        //if(h[i] >= b[d].h && h[j] >= b[d].h) {
        if(h[i] >= b[d].h) {
            if ( h[j] >= b[d].h) 
                dfs(j+1, r, d+1,a+b[d].a);
            break;
        }
    }
    for(int j = r,i = r-b[d].w+1; i >= l; i--,j--){
        //if ((h[j] >= b[d].h) && (h[i] >= b[d].h)) {
        if (h[i] >= b[d].h) {
            if (h[j] >= b[d].h)
                dfs(l,i-1, d+1,a+b[d].a);
            break;
        }
    }
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
    sort(b,b+N);
    dfs(0,B-1,0,0);
    out << ans << endl;
}
