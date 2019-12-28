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
int deg[10002];
int tree[20002];
int ind[10002];

bool v[10000];
void printt(){
    for(int i = 1; i <= 2*N; i++){
        cout << tree[i] << ' ';   
    }
    cout << endl;
    for(int i = 1; i <= N; i++){
        cout << ind[i] <<  ' ';   
    }
    cout << endl;
}
void build(int i){
    in >> N;
    int e[10002][2];
    for(int i = 1; i < N; i++){
        in >> e[i][0] >> e[i][1];
        deg[e[i][0]]++;
        deg[e[i][1]]++;
    }

    ind[1] = 1;
    for(int i = 2; i <= N+1; i++){
        ind[i] = ind[i-1]+deg[i-1];
    }
    int cnt[10002];
    memcpy(cnt,ind,sizeof(cnt));
    for(int i = 1; i < N; i++){
        tree[cnt[e[i][0]]] = e[i][1];
        tree[cnt[e[i][1]]] = e[i][0];
        cnt[e[i][0]]++;
        cnt[e[i][1]]++;
        
    }
}

void rebuild(){
    int cnt[10002];
    memcpy(cnt,ind,sizeof(cnt));
    int c = 1;
    for(int i = 1; i <= N; i++){
        for(int j = cnt[i]; j < cnt[i+1]; j++){
            if(tree[j] != 0){
                tree[c] = tree[j];
                c++;
            }
        }
        ind[i+1] = c;
    } 
}

void traverse(int i){
//    cout << i << endl;
    v[i] = true;
    for(int j = ind[i]; j < ind[i+1]; j++ ){
        if(v[tree[j]]) {
            tree[j] = 0;
            continue;
        }
        traverse(tree[j]);
    }
}

int dp[10005][3];
int dfs(int c, int s){ //  c state
//cout << c << " " << s << endl;

    if(dp[c][s] != -1){
        return dp[c][s];
    }
    int m = INF;
    if(s == 0){ //parent install, i haven't
        int cnt = 0;
        for(int i = ind[c]; i < ind[c+1]; i++){
            cnt += min(dfs(tree[i],1),dfs(tree[i],2));
        }
        m = min(m,cnt);
    } else if(s == 1){ //parent not,& i haven't 
        int mx = INF;
        for(int i = ind[c]; i < ind[c+1]; i++){
            int cnt = 0;
            for(int j = ind[c]; j < ind[c+1]; j++){
                if(i == j){
                    cnt+= dfs(tree[j],2);
                } else{
                    cnt+= min(dfs(tree[j],2),dfs(tree[j],1));
                }
            }
            mx = min(mx,cnt);
        }
        m = min(mx,m);
    } else{ //i install
        int cnt = 0;
        for(int i = ind[c]; i < ind[c+1]; i++){
            cnt += min(dfs(tree[i],1), min(dfs(tree[i],0),dfs(tree[i],2)));
            //cnt += min(dfs(i,0),dfs(i,2));
        }
        cnt++;
        m = min(m,cnt);
    }
//cout << "\t" << c << " " << s << " " << m <<endl;
    dp[c][s] = m;
    return m;
}

int main(){
    memset(dp,-1,sizeof(dp));
    build(1);
//    printt();
    traverse(1);
    rebuild();
    int ans =dfs(1,1);
//    cout << ans << endl;
    memset(v, 0, sizeof(v));
    ans = min(ans,dfs(1,2));
    out << ans << endl;
}
    
