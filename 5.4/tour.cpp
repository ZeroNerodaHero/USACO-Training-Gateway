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

void print(){
    for(int i = 0; i < N; i++){
        cout << i << ": ";
        for(auto& j: g[i]){
            cout << j <<  ' ';
        } 
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout.width(3);
            cout << dp[i][j];
        }
        cout << endl;
    }
}

void dfs(){
    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
#if 0
            for(auto& k: g[i]){
                if(dp[k][j] >= 0){
                    dp[i][j] = max(dp[i][j],dp[k][j] + 1);
                }
            }
#endif
            for(auto &k: g[j]){
                if(dp[i][k] >= 0){
                    dp[i][j] = max(dp[i][j],dp[i][k] + 1);
                }
            }
            dp[j][i] = dp[i][j];
        }
    }
    int ans = 1;
    for(auto& i: g[N-1]){
        if(dp[i][N-1] >= 0){
            ans = max(ans,dp[i][N-1]);
        }
    }
    out << ans << endl;
}

int main(){
    in >> N >> V;
    memset(dp,-1,sizeof(dp));
    for(int i = 0; i < N; i++){
        string s;
        in >> s;
        m[s] = i;
    }
    //N--;
    for(int i = 0; i < V; i++){
        string a,b;
        in >> a >> b;
        if(m[a] > m[b]) g[m[a]].push_back(m[b]);   
        else g[m[b]].push_back(m[a]);   
    }
    
    dfs();
    //print();
}
