/*
ID: billyz43
PROG: digest
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
#include <cmath>
#define INF (1<<28)
#define MAXN 1030
std::ifstream in("digest.in");
std::ofstream out("digest.out");
using namespace std;
int N,S;
int t[10][10];
int c[10];
bool v[10][10];

bool dfs(int x, int y, int tot){
    if(tot == 0) return true;
    if(y == c[x]){
        if(x == N-1){
            return false;
        }
        x++;
        y = 0;
    }

    if(tot >= t[x][y]){
        v[x][y] = true;
        if(dfs(x,y+1,tot-t[x][y])){
            return true;
        }
        v[x][y] = false;
    }
    return dfs(x,y+1,tot);
}

int main(){
    in >> N >> S;
    for(int i = 0; i < N; i++){
        in >> c[i];
        for(int j = 0; j < c[i]; j++){
            in >> t[i][j];
        }
    }
    dfs(0,0,S);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < c[i]; j++){
            if(v[i][j]) out << "*";
            else out << ".";
        }
        out << endl;
    }
}
