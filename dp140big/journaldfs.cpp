/*
ID: billyz43
PROG: journal
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <list>
#include <cmath>
#define INF 0x3F3F3F3F
std::ifstream in("journal.in");
std::ofstream out("journal.out");
using namespace std;
int par[70][2],fig[70];
int F,P,L;
int res = INF;
int res_left = INF;
#if 0
int depth =0;

void ent() {
    for (int i = 0; i<depth; ++i) cout << "    ";
    cout << depth << " * ";
    depth++;
}
    

void ext() {
    depth--;
}
#endif
void dfs(int p,int lp, int f0, int f1, int cnt){
//    ent();
//    cout << cnt << " P " << p << " " << lp  << "\t" << f0 << "-" << f1 << endl;
    if(p >= P && f1 == 0){
//    cout << "**** " << cnt <<" P " << p << " " << lp << " " << cnt << "\t" << f0 << "-" << f1 << endl;
        if(res >cnt|| (res==cnt&&(res_left > (L-lp)))) {
            res = cnt;
            res_left = L-lp;
        }
//        ext();
        return;
    }

    int tmp = lp;

if(f0 >0) {
    for(int i = f0; i <= f1; i++){
        tmp -= fig[i];    
        if(tmp < 0) {
            if (L !=lp){
                dfs(p, L, i, f1, cnt+1);
            }
//        ext();
            return;
        }
    }
    dfs(p, tmp, 0, 0, cnt);
}

    int fl=0, fr=0;
    while(tmp >= 0 && p<P){
        if(tmp >= par[p][0]) {
            if(fl ==0) {
                fl = fr = par[p][1];
            } else {
                fr = max(fr,par[p][1]);
            }
            dfs(p+1,tmp-par[p][0], fl, fr, cnt);
        } else {
            dfs(p, L, fl, fr, cnt+1);
        }
        tmp -= par[p][0];
        p++;
    }
//        ext();
}

int main(){
    in >> F >> P >> L;
    for(int i = 0; i < P; i++){
        in >> par[i][0] >> par[i][1];
    }
    for(int i = 1; i <= F; i++){
        in >> fig[i];
    }
    dfs(0, L, 0,0, 1);
    out << res << " " << res_left << endl;
}
