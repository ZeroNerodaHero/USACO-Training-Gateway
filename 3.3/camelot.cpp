/*
ID: billy
PROG: camelot
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
#include <list>
#include <algorithm>
#include <map>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("camelot.in");
std::ofstream out("camelot.out");
int R, C, size = 0;
int Kx, Ky;
int ans = 0x1F1F1F1F;
pair<int,int> Nx[800];
int dist[30][30][30][30];
int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {-2,2,-2,2,-1,1,-1,1};
int kx[8] = {1,1,1,-1,-1,-1,0,0};
int ky[8] = {-1,0,1,1,0,-1,-1,1};

struct point{
    int x, y, d;
    point(int x, int y, int d): x(x),y(y),d(d) {}
};
vector<point> p;

void print()
{
    for (int i = 0; i<R; ++i) {
        for (int j =0; j<C; ++j) {
        cout << "start: "<< i << ' ' << j << endl;
            for (int x = 0; x<R; ++x) {
                for (int y =0; y<C; ++y) {
                    cout << dist[i][j][x][y] << ' ';
                }cout << endl;
            }
        }
    }
}

void shortest(int x, int y){
    bool visited[R][C];
    memset(visited,0,sizeof(visited));

    dist[x][y][x][y] = 0;
    visited[x][y] = true;
    queue<point> q;
    q.push(point(x,y,0));

    while(!q.empty()){
        point tmp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if(nx >= 0 && nx < R &&
               ny >= 0 && ny < C &&
               !visited[nx][ny]){
                q.push(point(nx,ny,tmp.d+1));
                visited[nx][ny] = true;
                dist[x][y][nx][ny] = tmp.d+1;
            }       
        }
    }
}

void solve(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int sm = 0;
            for(int k = 0; k < size; k++){
                sm += dist[Nx[k].first][Nx[k].second][i][j];
            }   
//cout << "sm " << sm << " x/y:" << i << ", " << j <<endl;
            int smd = 0x1FFFF;
            for(int k = 0; k < p.size(); k++){
                int sd = 0;
                for(int l = 0; l < size; l++){
                    sd = dist[Nx[l].first][Nx[l].second][p[k].x][p[k].y];
                    sd += dist[p[k].x][p[k].y][i][j];
                    sd += p[k].d;
                    sd -= dist[Nx[l].first][Nx[l].second][i][j];
                    smd = min(smd,sd);
                    if(smd == 0) break;
                }
                smd = min(smd,sd);
                if(smd == 0) break;
            }
            sm += smd;
//cout << "smd " << smd<< endl;
            ans = min(ans,sm);
        }
    }
}

void find(){
    memset(dist, 1, sizeof(dist));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            shortest(i,j);
        }
    }
    //print();
    bool visited[R][C];
    memset(visited,0,sizeof(visited));
    queue<point> q;
    q.push(point(Kx,Ky,0));
    visited[Kx][Ky] =true;        
    p.push_back(point(Kx,Ky,0));

    while(!q.empty()){
        point tmp = q.front();
        q.pop();
        if(tmp.d > 1) continue;

        for(int i = 0; i < 8; i++){
            int nx = tmp.x + kx[i];
            int ny = tmp.y + ky[i];

            if(nx >= 0 && nx < R &&
               ny >= 0 && ny < C &&
               !visited[nx][ny]){
                q.push(point(nx,ny,tmp.d+1));   
                visited[nx][ny] = true;
                p.push_back(point(nx,ny,tmp.d+1));
            }
        }
    }
}

int main(){
    in >> R >> C;
    char kc;
    in >> kc >> Kx;
    Ky = kc-'A';
    Kx--;

    while(true){
        char a;
        int b;
        in >> a >> b;
//        cout << a << ' ' <<b << endl;
        if(in.eof()){
            break;
        }
        Nx[size].first = b-1;
        Nx[size++].second = a-'A';
    }
    //cout << size << endl;
    find();
    solve();
    out << ans << endl;
}
