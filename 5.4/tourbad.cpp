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
int dp[100][100];

int dfs(int c1, int c2){
    if(dp[c1][c2] >= 0) return dp[c1][c2];
    cout << "calling c1 " << c1 <<  "\tc2 " << c2 << endl;  

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
    dp[c1][c2] = v;
    //dp[c2][c1] = v;
    cout << "\t c1 " << c1 <<  "\tc2 " << c2 << " value " << v << endl;
    return dp[c1][c2];
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
    
    memset(dp,-1,sizeof(dp));
    dp[N][N] = 0;
    int ans = dfs(0,0);
    cout << "answer " << ans<< endl;
}
