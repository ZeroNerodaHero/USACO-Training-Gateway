/*
ID: billyz43
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#define INF 1e9
#define INF1 (INF-1)
using namespace std;
std::ifstream in("cowtour.in");
std::ofstream out("cowtour.out");
struct point{
    int x, y;
    point() {} 
    point(int x, int y): 
        x(x),y(y) {};
};
int N, M = 1;
point pts[150];
string con[150];
double d[150][150];
double m[150];
bool visited[150];
int id[150];
int f[151];
double big;

double dist(int i, int j){
    point &a = pts[id[i]],&b = pts[id[j]];
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline bool notINF(double a){
    return abs(a-INF) > 1;
}

void print(){
    cout << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << d[i][j] << '\t';
        }
        cout << endl;
    }
}

bool bfs(int n){
    int k = 0;
    for(; k < N; k++){
        if(!visited[k]) break;
    }
    if(k == N) return false;
    queue<int> q;
    q.push(k);
    visited[k] = true;
    int f1 = f[n-1];
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        id[f1++] = tmp;
        for(int i = 0; i < N; i++){
            if(con[tmp][i] == '1' && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    f[n] = f1;
    return true;
}

void warshall(int s, int e){
    for(int i = s; i < e; i++){
        for(int j = i+1; j < e; j++){
            if(con[id[i]][id[j]] == '1') d[i][j] = d[j][i] = dist(i,j);
            else d[i][j] = d[j][i] = INF;         
        }
    }
    for(int k = s; k < e; k++){
        for(int i = s; i < e; i++){
            for(int j  = s; j < e; j++){
                if(d[i][k] != INF && d[k][j] != INF){
                     d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }
    //print();
    for(int i = s; i < e; i++){
        for(int j = s; j < e; j++){
            if(d[i][j] != INF){
                m[i] = max(m[i], d[i][j]);
                big = max(big,m[i]);
            }
        }
    }
}

double mindist(){
    double shortest = INF;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(d[i][j] == 0){
                double len = m[i] + dist(i,j) + m[j];
                shortest = min(shortest,len);
            }
        }
    }
    return max(shortest,big);
}

int main(){
    in >> N;
    
    for(int i = 0; i < N; i++){
        int x, y;
        in >> x >> y;
        pts[i] = point(x,y);
    }    
    for(int i = 0; i < N; i++){
        in >> con[i];
    }
    while(bfs(M)){
        M++;
    }
    
    for(int i = 0; i < M; i++){
        warshall(f[i],f[i+1]);
    }
    //print();
    out.precision(6);
    out << fixed << mindist() << endl;
}
