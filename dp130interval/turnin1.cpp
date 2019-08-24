/*
ID: billy
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
bool v[1001];

void print(){
    for(int i = 0; i < C; i++){
        cout << cl[i].p << ' ' << cl[i].t <<  endl;;
    }
}

void dfs(int l, int t, int i, int j){
    if(i == j){
        int tot = t+abs(l-cl[i].p);
        if(tot < cl[i].t) tot = cl[i].t;
        tot += abs(B-cl[i].p);
        ans = min(ans,tot);
        return;
    }
    int tot = t+abs(l-cl[i].p);
    if(tot < cl[i].t) tot = cl[i].t;
    dfs(cl[i].p,tot,i+1,j);
    tot = t+abs(l-cl[j].p);
    if(tot < cl[j].t) tot = cl[j].t;
    dfs(cl[j].p,tot,i,j-1);
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
    
    dfs(0,0,0,C-1);
    out << ans << endl;
}
