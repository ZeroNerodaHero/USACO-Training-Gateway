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
    for(int i = 0; i < N; i++){
        if(!vy[y][i] && !vx[x][i]){
            vy[y][i] = true;
            vx[x][i] = true;
            dfs(x,y+1);
            vy[y][i] = false;
            vx[x][i] = false;
        }
    }
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        vy[i][i] = true;
    }
    dfs(1,0);
    out << cnt << endl;
}
