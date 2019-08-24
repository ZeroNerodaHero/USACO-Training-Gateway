/*
ID: billy
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

void printv(int d){
        cout << "\t\tdepth "<<d <<endl;;
    for(int i = 0; i < N; i++){
        cout << "\t\t";
        for(int j = 0; j < N; j++){
            cout << visited[i][j] << ' ';
        }
        cout << endl;
    }
}

bool dead(int x, int y){
    int t = 0; 
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N &&
           ny >= 0 && ny < N){
            if(!visited[nx][ny]){
                t++;
 //               cout << '\t' << x << ' ' << y << ' ' << t  << endl;
            }
        }
    }
    return t == 1;
}

void dfs(int x, int y, int d){
//cout << "**** " << d << ' ' << x << ' ' << y << endl; 
    if(x == N-1 && y == 0){
        if(d == N*N) ans++;
        return;
    }

//if(d==14) printv(d);
    if(d < (N *N-1)){
        int dedp = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
    
            if(nx >= 0 && nx < N && 
               ny >= 0 && ny < N &&
               !visited[nx][ny]){
                if(dead(nx,ny)) return;
                //if(dead(nx,ny)) dedp++;
            }
        }   
        //cout << d << ' ' << dedp << ' ' << x << ' ' << y << endl;
        if(dedp > 0) return;
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
