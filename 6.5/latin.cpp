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
int N;
int tt[8];
long long cnt;
int g[7][7];
bool vx[7][7];
bool vy[7][7];
bool v[7];

void print(){
    for(int i = 0; i < N; i++){
        cout << g[1][i] << ' ';
    }
    cout << endl;
}

int dfs2(int c){
    if(v[c]){
        return 0;
    }   
    v[c] = true;
    for(int i = 0; i < N; i++){
        if(g[1][i] == c){
            return 1+dfs2(g[0][i]);
        }
    }
}

int findl(){
    memset(v,0,sizeof(v));
    int m = 0;
    for(int i = 0; i < N; i++){
        if(!v[g[1][i]]){
            int b = dfs2(g[1][i]);
            m = max(m,b);
//            cout << b << ' ';
        }
    }
  //  cout << "\tm " << m << endl;
    return m;
}

void printall(){
    for(int i = 0; i < N; i++){
        cout << '\t';
        for(int j = 0; j < N; j++){
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}

int dfs(int x, int y){
    if(y == N){
        if(x >= N-2){
            return 1;
        }
        x++;
        y = 1;
    }   
    int big;
    if(x == 2 && y == 1){
//        print();
        big = findl();
//        if(big == 7) cout << tt[big] << endl;
        if(tt[big] != 0) return tt[big];
    }
    int s =0;
    for(int i = y; i < N; i++){
        if(!vy[y][g[x][i]] && !vx[x][g[x][i]]){
            vy[y][g[x][i]] = true;
            vx[x][g[x][i]] = true;
            swap(g[x][y],g[x][i]);
            s += dfs(x,y+1);
            swap(g[x][y],g[x][i]);
            vy[y][g[x][i]] = false;
            vx[x][g[x][i]] = false;
        }
    }
//    cout << x << ' ' << y << "\ts " << s << ' ' << endl;
    //if(s == 0){ printall(); }
    if(x == 2 && y == 1){
        cout << "big " << big << "\ts " << s << endl;
        tt[big] = s;
    }
    return s;
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
    cnt = dfs(1,1);
    cout << cnt << endl;
    for(int i = 2; i < N; i++){
        cnt *= i; 
    }
    out << cnt << endl;
}
