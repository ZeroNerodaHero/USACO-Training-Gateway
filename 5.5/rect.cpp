/*
ID: billy
PROG: picture
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;
std::ifstream in("picture.in");
std::ofstream out("picture.out");

int N;

struct edge{
    int s,e,h;
    bool st;
    edge(int s, int e,int h, bool st): s(s),e(e),h(h),st(st) {} 
    edge() {}
};
edge x[10002];
edge y[10002];

bool cmp(edge& a, edge& b){
    return a.h < b.h;
}

int sweep(edge ar[]){
    int cur[20001];
    memset(cur,0,sizeof(cur));
    int total = 0; 
    for(int i = 0; i < 2*N; i++){
        if(ar[i].st){
            for(int j = ar[i].s; j < ar[i].e; j++){
                if(cur[j] == 0) total++;    
                cur[j]++;
            }
        } else{
            for(int j = ar[i].s; j < ar[i].e; j++){
                cur[j]--;
                if(cur[j] == 0) total++;
            }
        }
    }
    return total;
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        int a,b,c,d;
        in >> a >> b >> c >> d;
        a += 10000;
        b += 10000;
        c += 10000;
        d += 10000;
        y[i] = edge(a,c,b,true);     
        y[i+N] = edge(a,c,d,false);     
        x[i] = edge(b,d,a,true);     
        x[i+N] = edge(b,d,c,false);     
    }
    sort(x,x+2*N,cmp);
    sort(y,y+2*N,cmp);

    int ans = sweep(x);
    ans += sweep(y);
    out << ans << endl;
}
