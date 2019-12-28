/*
ID: billyz43
PROG: robots
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("robots.in");
std::ofstream out("robots.out");
using namespace std;
bool m[2][22][22];
int r[2],w[2],gn[2];
int gx[2][10],gy[2][10];
int gl[2][10],gd[2][10];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
struct G{
    int x;
    int d;
};
struct maze{
    int x,y;
    G g[10];
};
int dir[128];

struct node{
    maze m[2];
    bool ok[2];
    int d;
};

node N;
unordered_map<unsigned long long, unsigned long long> p;

//typedef unsigned long long state;

// convert node to long long
void encode(unsigned long long & ss, node &s)
{
}

// convert long long to node
void decode(unsigned long long& ss, node &s)
{
}

void print(){
    for(int i = 0; i < 2; i++){
        cout << "maze " << r[i] << w[i] << endl;
        for(int j = 1; j <= r[i]; j++){          
            for(int k = 1; k <= w[i]; k++){
                if(m[i][j][k]) cout << '.';
                else cout << "#";
            }
            cout << endl;
        }
        cout << endl;
        cout << "gar" << endl;
        for(int j = 0; j < gn[i]; j++){
            cout << gx[i][j] << ',' << gy[i][j] << endl;
        }   
        cout << endl;
        cout << endl;
    }
}

void bfs(){
    unsigned long long s;
    encode(s, N);
    p[s] = s;
    queue<unsigned long long> q;
    q.push(s);

    while(!q.empty()){
        unsigned long long s  = q.front();
        q.pop();
        node tmp;
        decode(s, tmp);
        bool o[2]= {false,false}; 

        for(int i = 0; i < 4; i++){
            o[0] = false;
            o[1] = false;
            for(int j = 0; j < 2; j++){
                if(tmp.ok[j]){
                    o[j] = false;
                    continue;
                }
                
            }
            if(tmp.ok[0] && tmp.ok[1]){
////print ans
                return;
            }
            if(o[0] && o[1]){
//queue
            }
        }
    }
}

int main(){
    dir['W'] = 0;
    dir['E'] = 1;
    dir['N'] = 2;
    dir['S'] = 3;
    for(int i = 0; i < 2; i++){
        in >> r[i] >> w[i];
        for(int j = 1; j <= r[i]; j++){
            for(int k = 1; k <= w[i]; k++){
                char t;
                in >> t;

                if(t == '.' || t == 'X'){
                    m[i][j][k] = 1;
                }            
                if(t == 'X'){
                    N.m[i].x = j;                    
                    N.m[i].y = k;                    
                }
            }
        }
        in >> gn[i];
        for(int j = 0; j < gn[i]; j++){
            char di;
            in >> gx[i][j] >> gy[i][j] >> gl[i][j] >>di;            
            gd[i][j] = dir[di];
            N.m[i].g[j].d = dir[di];
        }
    }
    print();
}
