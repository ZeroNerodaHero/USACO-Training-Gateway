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
int par[70][2],fig[72], gig[72];
int F,P,L;

#if 0
int depth =0;

void ent() {
    for (int i = 0; i<depth; ++i) cout << " ";
    cout << depth << "*";
    depth++;
}

void ext() {
    depth--;
}
#endif


const int INF= 0x1f1f;
struct node{
    short cnt,lp;
    node(short _cnt=0, short _lp=0): cnt(_cnt),lp(_lp){}
    bool operator < (const node& o) const{
        if(cnt == o.cnt) return lp < o.lp;
        return cnt < o.cnt;
    }

    node & operator = (const node &o) {
        cnt = o.cnt;
        lp = o.lp;
        return *this;
    }
};

node big(INF, INF);
int pi[100];
int fi[100];

void print(){
    for(int i = 0; i < P; i++){
        cout <<  pi[i] << ' ';
    } cout <<endl;
    for(int i = 1; i <= F; i++){
        cout <<  fi[i] << ' ';
    } cout <<endl;
    for(int i = 1; i <= F; i++){
        cout <<  fig[i] << ' ';
    } cout <<endl;
}

node dp[72][72][101];
node dfs(int p, int f, int lp){
//ent();
//cout << " P " << p << " F " <<f << " Lp " << lp << endl;
    if(p >= P && f >  F){
//ext();
        return node(1, L-lp);
    }

    if(dp[p][f][lp]< big){
//ext();
        return dp[p][f][lp]; 
    }
    node ret = big, ans;

    if(lp == L) {
        if(f>1 && p <= fi[f-1]) {
//ext();
            for(int i = p; i <= fi[f-1]; i++){
                lp -= par[i][0];
                if(lp < 0) return big;
                //if(lp < 0) {cout<< "big" << endl;return big;}
            }
            ans = dfs(fi[f-1]+1,f,lp);
            if(ans < ret) ret = ans;
            dp[p][f][L] = ret;
            return ret;
        }

        if(p>0 && f <= pi[p-1]){
//ext();
            for(int i = f; i <= pi[p-1]; i++){
                lp -= fig[i];
                if(lp < 0) return big;
                //if(lp < 0) {cout<< "big" << endl;return big;}
            }
            ans = dfs(p,pi[p-1]+1,lp);
            if(ans < ret) ret = ans;
            dp[p][f][L] = ret;
            return ret;
        }
    }

    bool np= true;
    if(p < P && lp >=  par[p][0]){
        np = false;
        ans = dfs(p+1, f, lp - par[p][0]);
        if(ans < ret) ret = ans;
    } 

    if(f <= F && lp >= fig[f]){
        np = false;
        ans = dfs(p, f+1,lp-fig[f]);
        if(ans < ret) ret = ans;
    }

    if(lp < L) {
        ans = dfs(p, f, L);
        ans.cnt++;
        if(ans < ret) ret = ans;
    }

//ext();
    dp[p][f][lp] = ret;
    return ret;
}

int main(){
    in >> F >> P >> L;
    for(int i = 0; i < P; i++){
        in >> par[i][0] >> par[i][1];
    }
    for(int i = 1; i <= F; i++){
        in >> gig[i];
    }

    int cf = 0;
    for(int i = 0; i < P; i++){
        if(par[i][1] != 0){
            cf++;
            fig[cf] = gig[par[i][1]];
            fi[cf] = i;
        }
        pi[i] = cf;
    }
    fi[0] = -1;

    memset(dp,0x1f,sizeof(dp));
//print();   
    node ret;
    ret = node(2,5);
    //cout << "return " << ret.cnt << ret.lp << endl;
    ret = dfs(0, 1, L);
    out << ret.cnt << " " << ret.lp << endl;
}
