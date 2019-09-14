/*
ID: billyz43
PROG: psolve
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
std::ifstream in("psolve.in");
std::ofstream out("psolve.out");
using namespace std;

struct prob{
    int bp, ap;
};

int M, P,ans = INT_MAX;
prob q[301];

void dfs(int AP,int cp,int m){
    cout << AP << ' ' << cp << ' ' << m << endl;
    if(cp >= P){
        ans = min(ans,m);
        return;
    }
    if(AP > M){
        return;
    }
    
    int l = M-AP;
    if(l == 0){
        dfs(0,cp,m+1);
        return;
    }
    int lp = 0;
    int cpt = cp;

    while(l >= q[cpt].bp && cpt < P){ 
        l -= q[cpt].bp;
        lp += q[cpt].ap;
        cpt++;
        dfs(lp,cpt,m+1);
    }
}

int main(){
    in >> M >> P;
    cout << "M " <<M << "\tP " << P << endl;
    for(int i = 0; i < P; i++){
        in >> q[i].bp >> q[i].ap;
    }
    dfs(0,0,2);
    cout << ans << endl;
}
