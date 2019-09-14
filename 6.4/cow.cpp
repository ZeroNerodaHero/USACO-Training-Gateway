/*
ID: billyz43
PROG: wissqu
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>
using namespace std;
std::ifstream in("wissqu.in");
std::ofstream out("wissqu.out");

struct p{
    int c, x,y;
    p() {};
    void set(int c, int x, int y){
        this->c = c;
        this->x = x;
        this->y = y;
    }
};

int curf[4][4];
bool v[4][4];
int tot[5] = {3,3,3,4,3};
int cnt = 0;
p path[16];
bool fnd = false;
int dx[8] = {-1,-1,-1,1,1,1,0,0};
int dy[8] = {-1,0,1,-1,0,1,-1,1};

void print(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << curf[i][j] << ' ';
        }
        cout << endl;
    }
}
    
bool check(int a, int x, int y){
    if(curf[x][y] == a) return false;;
    for(int i = 0; i < 8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && 
           curf[nx][ny] == a) return false;

    }
#if 0
    if(x > 0 && y > 0 && curf[x-1][y-1] == a) return false;
    if(x < 3 && y < 3 && curf[x+1][y+1] == a) return false;

    if(y > 0 && curf[x][y-1] == a) return false;
    if(x > 0 && curf[x-1][y] == a) return false;

    if(x > 0 && y < 3 && curf[x-1][y+1] == a) return false;
    if(x < 3 && y > 0 && curf[x+1][y-1] == a) return false;

    if(y < 3 && curf[x][y+1] == a) return false;
    if(x < 3 && curf[x+1][y] == a) return false;
//    curf[x][y] = a; 
#endif

    return true;
}

bool dfs(int d){
    if(d == 16){
        fnd = true;
        cnt++;
    }
    int l = 0, r = 5;
    if(d == 0){
        l = 3;
        r = 4;
    }
    for(int k = l; k < r; k++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(!v[i][j]){
                    if(tot[k] > 0 && check(k,i,j)){
                        int cha = curf[i][j];
                        curf[i][j] = k;
                        v[i][j] = true;
                        tot[k]--;
                        if(!fnd) path[d].set(k,i,j);
                        dfs(d+1);
                        tot[k]++;
                        curf[i][j] = cha;
                        v[i][j] = false;
                    }
                }
            }
        }
    }
    return false;
}


int main(){
    for(int i = 0; i < 4; i++){
        string s;
        in >> s;
        for(int j = 0; j < 4; j++){
            curf[i][j] = s[j]-'A';
        }
    }
//    print();
    dfs(0);
    for(int i = 0; i < 16; i++){
        out << char(path[i].c+'A') << ' ' << path[i].x+1 << ' ' << path[i].y+1 << endl;
    }
    out << cnt << endl;
}
