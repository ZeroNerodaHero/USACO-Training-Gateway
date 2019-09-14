/*
ID: billyz43
PROG: fence
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("fence.in");
std::ofstream out("fence.out");

list<int> g[501];
vector<int> cir;

void dfs(int i){
    stack<int> s;
    s.push(i);
    while(!s.empty()){
        i = s.top();
        s.pop();
        while(g[i].size()){
            int j = g[i].front();
            g[i].pop_front();
            g[j].erase(find(g[j].begin(),g[j].end(),i));
            s.push(i);
            i = j;
        } 
        cir.push_back(i);
    }
    for(int j = cir.size()-1; j >= 0; j--){
        out << cir[j] << endl;
    }
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

    int u = 0; 
    for(auto &i:m){
        g[i.first].sort();
        if((g[i.first].size()&1)){
            if(u == 0) u = i.first;
        }
/*
        cout << i.first << '\t';
        for(auto j:g[i.first]){
            cout << j << ' ';
        } cout << endl;
*/
    }
    if(u == 0) u = m.begin()->first;
  //  cout << "start " << u << endl;
    dfs(u);
}
