/*
ID: billyz43
PROG: path
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
#define INF 999999
std::ifstream in("path.in");
std::ofstream out("path.out");
using namespace std;

struct node{
    int b,t;
    node(int b, int t): b(b),t(t) {}
};

int N, M,K;
list<node> g[5001];

int dfs(int c, int t){
    if(t == K){
        if(c == N) return 0;
        return INF;
    }
     
    int ret = INF;
    for(auto i: g[c]){
        ret = min(ret,dfs(i.b,t+1)+i.t);
    }
    return ret;
}

int main(){
    in >> N >> M >> K;
    for(int i = 0; i < M; i++){
        int a,b,t;
        in >> a >> b >> t;
        g[a].push_back(node(b,t));
        g[b].push_back(node(a,t));
    }

    int ans = dfs(1,0);
    cout << ans << endl;
}
