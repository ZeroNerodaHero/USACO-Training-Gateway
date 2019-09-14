/*
ID: billyz43
PROG: vans
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("vans.in");
std::ofstream out("vans.out");
int N,ans = 0;
bool visited[4][1001];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void dfs(int x, int y, int t){
    if(t == 4*N){
        if((x == 0 && y == 1) || (x== 1 && y==0)){
            ans++;
        } 
        return;
    }
    visited[y][x] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < N && ny >= 0 && ny < 4 && !visited[ny][nx]){
            dfs(nx,ny,t+1);
        }
    }
    visited[y][x] = false;
}

int main(){
    in >> N;
    dfs(0,0,1);
    out << ans << endl;
}
