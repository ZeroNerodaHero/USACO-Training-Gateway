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
int res = 1;
int dp[101][101];

void dfs(int c1, int c2, int t){
//    cout << "c1 " << c1 <<  "\tc2 " << c2 << "\tt"<<t <<endl;  
    if(dp[c1][c2] >= t){
        return;
    }
    dp[c1][c2] = dp[c2][c1] =t;
    if(c1 == N && c2 == N){
        if(res < t){
            res = t;
        }
        return;
    }
    int v = 0;
    if(c1 < N){
        for(auto& i: g[c1]){
            if(i == N || !visited[i]){
                visited[i] = true;
                dfs(i,c2,t+1); 
                visited[i] = false;
            }
        }
    }
    if(c2 < N){
        for(auto& i: g[c2]){
            if(i == N || !visited[i]){
                visited[i] = true;
                dfs(c1,i,t+1); 
                visited[i] = false;
            }
        }
    }
    //cout << "\tvalue " << v  << endl; 
}

int main(){
    in >> N >> V;
    memset(dp,-1,sizeof(dp));
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
    
    dfs(0,0,0);
    out << res << endl;
}
