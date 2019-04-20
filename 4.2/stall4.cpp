/*
ID: billy
PROG: stall4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
std::ifstream in("stall4.in");
std::ofstream out("stall4.out");

int con[201][201];
int N, M;
int matches[201];
void addEdge(int a, int b){
    con[a][b] = 1;
}

bool bmp(int u, bool visited[]){
    for(int i = 1; i <= M; i++){
        if(con[u][i] > 0 && !visited[i]){
            visited[i] = true;
            if(matches[i] == 0 || bmp(matches[i],visited)){
                matches[i] = u;
                return true;
            }            
        }
    }
    return false;
}

int amaximum(){
    int match = 0;
    bool visited[M+1];
    for(int i = 1; i <= N; i++){
        memset(visited,0,sizeof(visited));
        if(bmp(i,visited)){
            match++;
        }
    }

    return match;
}

void print(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cout << con[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
        
    for(int i = 1; i <= M; i++){
        cout << i << ' ' << matches[i] << endl;
    }
}

int main(){
    in >> N >> M;

    for(int i = 1; i <= N; i++){
        int c;
        in >> c;
        for(int j = 0; j < c; j++){
            int d;
            in >> d;
            addEdge(i,d);
        }
    }
    
    out << amaximum() << std::endl;   
//    print();
}
