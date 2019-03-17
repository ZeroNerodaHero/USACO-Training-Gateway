/*
ID: billy
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
std::ifstream in("agrinet.in");
std::ofstream out("agrinet.out");

struct edge{
    int u,v,d;
    edge(int u,int v,int d): u(u),v(v),d(d) {}
    bool operator <(const edge &o) const{
        return d < o.d;
    }
};
int N;
int p[100];

void makeset(){
    for(int i = 0; i < N; i++){
        p[i] = i;
    }
}

int find(int u){
    if(p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

void merge(int u, int v){
    int pu = find(u);
    int pv = find(v);

    p[pu] = pv;
}

int main(){
    in >> N;
    int con[100][100];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> con[i][j];
        }
    }
    vector<edge> e;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            e.push_back(edge(i,j,con[i][j]));
        } 
    }
    sort(e.begin(),e.end());

    int sum = 0, n = 1, i = 0;
    makeset();
    while(n < N){
        int u = e[i].u;
        int v = e[i].v;
//        cout << n << ' '<<u << ' ' << v << ' '<< i << ' ' << e[i].d<< endl;
        int pu = find(u);
        int pv = find(v);
        if(pu != pv){
    //        merge(u,v);
            p[pu] = pv;
            sum += e[i].d;
            n++;
        }
        i++;
    }
    out << sum << endl;
}
