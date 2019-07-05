/*
ID: billy
PROG: tour
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;
std::ifstream in("tour.in");
std::ofstream out("tour.out");
int N, V;
unordered_map<string,int> m;
list<int> g[105];
bool visited[100];

int dfs(int c1, int c2){
    //cout << "c1 " << c1 <<  "\tc2 " << c2 << endl;  
    if(c1 == N && c2 == N){
        return 0;
    }
    int v = 0;
    if(c1 < N){
        for(auto& i: g[c1]){
            if(i == N || !visited[i]){
                visited[i] = true;
                v = max(v,dfs(i,c2)+1);
                visited[i] = false;
            }
        }
    }
    if(c2 < N){
        for(auto& i: g[c2]){
            if(i == N || !visited[i]){
                visited[i] = true;
                v = max(v,dfs(c1,i)+1);
                visited[i] = false;
            }
        }
    }
    //cout << "\tvalue " << v  << endl; 
    return v;
}

int main(){
    in >> N >> V;
    for(int i = 0; i < N; i++){
        string s;
        in >> s;
        m[s] = i;
    }
    N--;
    for(int i = 0; i < V; i++){
        string a,b;
        in >> a >> b;
        if(m[a] < m[b]) g[m[a]].push_back(m[b]);   
        else g[m[b]].push_back(m[a]);   
    }
    
    int ans = dfs(0,0);
    out << ans<< endl;
}
