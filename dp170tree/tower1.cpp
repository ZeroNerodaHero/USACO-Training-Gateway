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
list<int> e[10000];

bool v[10000];
bool isV(){
    for(int i = 1; i <= N; i++){
        if(v[i] == false) return false;
    }
    return true;
}
bool use[1000];
void print(){
    for(int i = 1; i < N; i++){
        cout << use[i] << ' ';
    }
    cout << endl;
}
int dfs(int cur,int cnt){
    if(cur == N+1){
        if(isV()){
            print();
            return cnt;
        }
        return 0x3f3f3f3f;
    }
    int ans =dfs(cur+1,cnt);
    v[cur] = true;
    use[cur] = true;
    for(auto i: e[cur]){
        v[i] = true;
    }
    ans = min(ans,dfs(cur+1,cnt+1));
    for(auto i: e[cur]){
        v[i] = false;
    }
    v[cur] = false;
    use[cur] = false;
    return ans;
}
//bool v[10001];
void build(int i){
   v[i] = true;
    auto j = e[i].begin();
    while(j!= e[i].end()){
        if(v[*j]){
            j = e[i].erase(j);
        } else{
            v[*j] =  true;
            j++;
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

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        int a,b;    
        in >> a >>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    build(1);
    traverse(1);
}
    
