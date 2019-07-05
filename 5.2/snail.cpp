/*
ID: billy
PROG: snail
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <utility>
using namespace std;
std::ifstream in("snail.in");
std::ofstream out("snail.out");
int N;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool g[120][120];
bool v[120][120];
int res = 0;

void print(int s){
    cout << s << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<< v[i][j] << ' ';
        }
        cout << endl;
    }
        cout << endl;
}

void dfs(int x, int y, int dist, int dir){
    int step = 0;
 //           print(dist+step);
    do{
        if(x < 0 || x >= N || y < 0 || y >= N || g[x][y]){
            x -= dx[dir];
            y -= dy[dir];
            int d1 = dir^2;
            int d2 = dir^3;
            int nx = x+dx[d1];
            int ny = y+dy[d1];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !g[nx][ny]){
                dfs(x+dx[d1],y+dy[d1],dist+step,d1);
            }
            nx = x+dx[d2];
            ny = y+dy[d2];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !g[nx][ny]){
                dfs(x+dx[d2],y+dy[d2],dist+step,d2);
            }
            res = max(res,dist+step);
            break;
        } 
        if(v[x][y]){
            res = max(res,dist+step);
            x -= dx[dir];
            y -= dy[dir];
            break; 
        }   
        v[x][y] = true;
        
        x += dx[dir];
        y += dy[dir];
        step++;
    } while(true);

    for(int i = 0; i < step; i++){
            v[x][y] = false;
            x -= dx[dir];
            y -= dy[dir];
    }
}

int main(){
    int c;
    in >> N >> c;
    for(int i = 0 ; i < c; i++){
        char a; int b;
        in >> a >> b;
//        cout << a << ' ' << b << endl;

        g[a-'A'][b-1] = true;        
    }
    
    dfs(0,0,0,2);
    dfs(0,0,0,0);
    out << res << endl;
}
