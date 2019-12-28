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
std::ifstream in("journal.in");
std::ofstream out("journal.out");
using namespace std;
int par[70][2],fig[70];
int F,P,L;

const int INF= 0x1f1f;
struct node{
    short cnt,lp;
    node(short _cnt=0, short _lp=0): cnt(_cnt),lp(_lp){}
    bool operator < (const node& o) const{
        return cnt < o.cnt;
    }

    node & operator = (const node &o) {
        cnt = o.cnt;
        lp = o.lp;
        return *this;
    }
};

node big(INF, INF);

unordered_map<int,node> dp;
//node dp[40][40][40][40];
node dfs(int p,int lp, int f0, int f1, int cnt){
    //cout << cnt << " P " << p << " " << lp  << "\t" << f0 << "-" << f1 << endl;
    if(p >= P && f1 == 0){
//        cout << "**** " << cnt <<" P " << p << " " << lp << "\t" << f0 << "-" << f1 <<endl;
        return node(1, L-lp);
    }
    /*
    if(dp[p][lp][f0][f1]< big){
        return dp[p][lp][f0][f1];
    }
    */
    int id = ((p<<24)|(lp<<16)|(f0<<8)|(f1));    
    if(dp.find(id) != dp.end()) return dp[id];

    node ret = big, ans;
    int tmp = lp;

if(f0 >0) {
    for(int i = f0; i <= f1; i++){
        tmp -= fig[i];    
        if(tmp < 0) {
            if (L !=lp){
                ans = dfs(p, L, i, f1, cnt+1);
                ans.cnt++;
                if(ans < ret) {
 //                   cout << "ans value " << ans.cnt << " " << ans.lp << endl;
                    ret = ans;
                }
            }
            return ret;
        }
    }
    ans = dfs(p, tmp, 0, 0, cnt);
    if(ans < ret) ret = ans;
}

    int fl=0, fr=0;
    while(tmp >= 0 && p<P){
        if(tmp >= par[p][0]) {
            if(fl ==0) {
                fl = fr = par[p][1];
            } else {
                fr = max(fr,par[p][1]);
            }
            ans = dfs(p+1,tmp-par[p][0], fl, fr, cnt);
            if(ans < ret) {
//                cout << "ans value " << ans.cnt << " " << ans.lp << endl;
                ret = ans;
            }
        } else {
            ans = dfs(p, L, fl, fr, cnt+1);
            ans.cnt++;
            if(ans < ret) ret = ans;
        }
        tmp -= par[p][0];
        p++;
    }

//    cout << "return value" << ret.cnt << " " <<ret.lp << endl;
    dp[id] = ret;
    return ret;
}

int main(){
    in >> F >> P >> L;
    for(int i = 0; i < P; i++){
        in >> par[i][0] >> par[i][1];
    }
    for(int i = 1; i <= F; i++){
        in >> fig[i];
    }
//    memset(dp,0x1f,sizeof(dp));
   
    node ret;
    ret = node(2,5);
    //cout << "return " << ret.cnt << ret.lp << endl;
    ret = dfs(0, L, 0,0, 1);
    out << ret.cnt << " " << ret.lp << endl;
}
