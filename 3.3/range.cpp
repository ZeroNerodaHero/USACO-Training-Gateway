/*
ID: billyz43
PROG: fence
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("fence.in");
std::ofstream out("fence.out");

list<int> g[501];
vector<int> cir;

void dfs(int s){
    while(!g[s].empty()){
        int v = g[s].back();
        //cout << s << ' ' << v << endl;
        g[s].pop_back();
        g[v].erase(find(g[v].begin(),g[v].end(),s));
        dfs(v);
        /*
        int v = g[s].front();
        cout << s << ' ' << v << endl;
        g[s].pop_front();
        g[v].erase(find(g[v].begin(),g[v].end(),s));
        dfs(v);
        */
    }
    out << s << endl;
}

int main(){
    int F;
    in >> F;
    map<int,int> m;
    for(int i = 0; i < F; i++){
        int a, b;
        in >> a >> b;
        m[a] = m[b] = 1;
        g[a].push_back(b);       
        g[b].push_back(a);       
    }

    int u = m.begin()->first;
    for(auto &i:m){
        g[i.first].sort();
        if((g[i.first].size()&1)){
            u = i.first;
        }
    }
//    cout << "start " << u << endl;
    dfs(u);
}
