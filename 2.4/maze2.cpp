/*
ID: billyz43
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;
std::ifstream in("maze1.in");
std::ofstream out("maze1.out");
int W, H;
string m[250];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct point{
    int x, y, day;
    point() {}
    point(int x, int y, int day):
        x(x),y(y),day(day) {}
};

queue<point> q;
bool visited[250][250];

inline void enque(int x, int y,int days = 1){
    q.push(point(x,y,days));
    visited[x][y] = true;;
}

int flood(){
    point tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        int x = tmp.x, y = tmp.y, day = tmp.day;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            //cout << nx << ' ' << ny << ' ' << day << endl;
            if(m[nx][ny] == ' '){
                //cout << nx << ' ' << ny << ' ' << day << endl;
                nx += dx[i]; 
                ny += dy[i];
                if(nx >= 0 && nx < H &&
                ny >= 0 && ny < W &&
                !visited[nx][ny] ){
                    enque(nx,ny,day+1);
                }
            }
        } 
    }
    return tmp.day;
}

int main(){
    in >> W >> H;
    W = 2*W+1;
    H = 2*H+1;
    getline(in,m[0]);
    for(int i = 0; i < H; i++){
        getline(in,m[i]);
    }

    for(int i = 0; i < W; i++){
        if(m[0][i] == ' '){
            enque(1,i);
        }
        if(m[H-1][i] == ' '){
            enque(H-2,i);
        }
    }
    for(int i = 0; i < H; i++){
        if(m[i][0] == ' '){
            enque(i,1);
        }
        if(m[i][W-1] == ' '){
            enque(i,W-2);
        }
    }   
    out << flood() << endl;
}
