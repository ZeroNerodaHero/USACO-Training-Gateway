/*
ID: billyz43
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
std::ifstream in("maze1.in");
std::ofstream out("maze1.out");
int W, H;
int maxday = 0;
int maze[100][150];

string m[150];

int dx[4] = {-2,0,2,0};
int dy[4] = {0,2,0,-2};
int checkdx[4] = {-1,0,1,0};
int checkdy[4] = {0,1,0,-1};

struct point{
    int x, y, day;
    point(int x, int y, int day):
        x(x),y(y),day(day) {}
};

void flood(int i, int j){
    bool visited[2*W+1][2*H+1];
    for(int i = 0; i < 2*H+1; i++){
        for(int j = 0; j < 2*W+1; j++){
            visited[i][j] = false;
        }
    }
    queue<point> q;
    q.push(point(i,j,0));
    while(!q.empty()){
        point tmp = q.front();
        q.pop();
        int x = tmp.x, y = tmp.y, day = tmp.day;
        maxday = max(day,maxday);
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int cnx = x + checkdx[i];
            int cny = y + checkdy[i];
            if(nx >= 0 && nx < 2*H+1 &&
               ny >= 0 && ny < 2*W+1 &&
               m[cnx][cny] == ' ' &&
               !visited[nx][ny] )
                q.push(point(nx,ny,day+1));
        } 
    }
}

int main(){
    in >> W >> H;
    getline(in,m[0]);
    for(int i = 0; i < 2*H+1; i++){
        //in.getline(m[i],2*W+1);
        getline(in,m[i]);
    }
    for(int i = 0; i < 2*W+1; i++){
        if(m[0][i] == ' '){
            flood(0,i);
        }
        if(m[2*H][i] == ' '){
            flood(2*H-1,i);
        }
    }
    cout << maxday << endl;
    for(int i = 0; i < 2*H+1; i++){
        if(m[i][0] == ' '){
            flood(i,0);
        }
        if(m[i][2*W] == ' '){
            flood(i,2*W-1);
        }
    }   
    out << maxday << endl;
}
