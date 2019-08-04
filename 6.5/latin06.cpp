/*
ID: billy
PROG: latin
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
std::ifstream in("latin.in");
std::ofstream out("latin.out");
int N,cnt;
int g[7][7];
bool vx[7][7];
bool vy[7][7];

void dfs(int x, int y){
    if(y == N){
        if(x >= N-2){
            cnt++;
            return;
        }
        x++;
        y = 0;
    }   
    for(int i = y; i < N; i++){
        if(!vy[y][g[x][i]] && !vx[x][g[x][i]]){
            vy[y][g[x][i]] = true;
            vx[x][g[x][i]] = true;
            swap(g[x][y],g[x][i]);
            dfs(x,y+1);
            swap(g[x][y],g[x][i]);
            vy[y][g[x][i]] = false;
            vx[x][g[x][i]] = false;
        }
    }
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            g[i][j] = j;
        }
        vy[i][i] = true;
        swap(g[i][0],g[i][i]);
        vx[i][i] = true;
    }
    dfs(1,0);
    out << cnt << endl;
}
