/*
ID: billyz43
PROG: betsy
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>
#include <math.h>
using namespace std;
std::ifstream in("betsy.in");
std::ofstream out("betsy.out");
int N;
bool visited[7][7];
int ans = 0;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void dfs(int x, int y, int d){
    if(x == N-1 && y == 0){
        if(d == N*N) ans++;
        return;
    }
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(nx >= 0 && nx < N && 
           ny >= 0 && ny < N &&
           !visited[nx][ny]){
            dfs(nx,ny,d+1);
        }
    }   
    visited[x][y] = false;
}

int main(){
    in >> N;
    dfs(0,0,1);
    out << ans << endl;
}
