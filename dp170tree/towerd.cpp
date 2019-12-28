/*
ID: billyz43
PROG: tower
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <iomanip>
#include <list>
#define INF (1<<28)
std::ifstream in("tower.in");
std::ofstream out("tower.out");
using namespace std;
bool m[14][14];
int N;
vector<int> e[10000];

bool v[10000];
void build(int i){
    v[i] = true;
    for(auto &j: e[i]) {
        if(v[j]){
            j = 0;
        } else{
            v[j] =  true;
        }
    } 

    for(auto k: e[i]){
        build(k);
    }
}

void traverse(int i){
    cout << i << endl;
    for(auto j: e[i]){
        traverse(j);
    }
}

int dp[10005][3];
int dfs(int c, int s){ //  c state
//cout << c << " " << s << endl;
#if 0
    if(e[c].empty()){
//cout << "\t*** " << c << " " << s << " " << (s==1)  <<endl;
        if(s == 0) return 0;
        return 1;
    }
#endif
    if(dp[c][s] != -1){
        return dp[c][s];
    }
    int m = INF;
    if(s == 0){ //parent install, i haven't
        int cnt = 0;
        for(auto i : e[c]){
            if(i ==0) continue;
            cnt += min(dfs(i,1),dfs(i,2));
        }
        m = min(m,cnt);
    } else if(s == 1){ //parent not,& i haven't 
        int mx = INF;
        for(auto i : e[c]){
            if(i ==0) continue;
            int cnt = 0;
            for(auto j : e[c]){    
                if(j ==0) continue;
                if(i == j){
                    cnt+= dfs(j,2);
                } else{
                    cnt+= min(dfs(j,2),dfs(j,1));
                }
            }
            mx = min(mx,cnt);
        }
        m = min(mx,m);
    } else{ //i install
        int cnt = 0;
        for(auto i : e[c]){
            if(i ==0) continue;
            cnt += min(dfs(i,1), min(dfs(i,0),dfs(i,2)));
            //cnt += min(dfs(i,0),dfs(i,2));
        }
        cnt++;
        m = min(m,cnt);
    }
//cout << "\t" << c << " " << s << " " << m <<endl;
    dp[c][s] = m;
    return m;
}

void print() {
    for (int i = 1; i<=N; ++ i) {
        cout << i << " : ";
        for (auto j:e[i]) cout << j << " "; cout << endl;
    }
}
int main(){
    in >> N;
    for(int i = 1; i < N; i++){
        int a,b;    
        in >> a >>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    //print();
    memset(dp,-1,sizeof(dp));
    build(1);
//traverse(1);
    int ans =dfs(1,1);
    ans = min(ans,dfs(1,2));
    out << ans << endl;
}
    
