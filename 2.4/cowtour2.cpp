/*
ID: billy
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
int N;
point pts[150];
string con[150];
double d[150][150];
double m[150];
bool visited[150];
int id[150];
int f1;
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
bool check(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(con[i][j] == '1') return false;
        }
    }
    double shortest = INF;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            shortest= min(shortest,dist(i,j));
        }
    }
    out.precision(6);
    out << fixed << shortest << endl;
    return true;
}       
void bfs(){
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        
        for(int i = 0; i < N; i++){
            if(con[tmp][i] == '1' && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(visited[i]) id[f1++] = i;
    }   
    int f2 = f1;
    for(int i = 0; i < N; i++){
        if(!visited[i]) id[f2++] = i;
    }   
}
void dfs(int a){
    visited[a] = true;
    for(int i = 0; i < N; i++){
        if(con[a][i] == '1' && !visited[i]){
            dfs(i);
        }
    }
}

void dfs(){
    dfs(0);

    for(int i = 0; i < N; i++){
        if(visited[i]) id[f1++] = i;
    }
    int f2 = f1;
    for(int i = 0; i < N; i++){
        if(!visited[i]) id[f2++] = i;
    }    
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
    for(int i = 0; i < f1; i++){
        for(int j = f1; j < N; j++){
            double len = m[i] + dist(i,j) + m[j];
            shortest = min(shortest,len);
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
    bfs();
//    dfs();
    if(check()) return 0;  
    warshall(0,f1);
    warshall(f1,N);
    //print();
    out.precision(6);
    out << fixed << mindist() << endl;
}
