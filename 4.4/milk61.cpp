/*
ID: billyz43
PROG: milk6
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
std::ifstream in("milk6.in");
std::ofstream out("milk6.out");
int N, M;
int adj[33][33];
int r[33][33];
int p[33];
   
struct path{
    int a,b,d;
    path(int a, int b, int d):a(a),b(b),c(c): {}
};
path edge[33];

void minc(){
    
}

void print(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    in >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b, d;
        in >> a >> b >> d;
        edge[i+1] = path(a,b,d); 
        adj[a][b] = d;
        r[a][b] = d;
    }
//    print();
    minc();
    
}
