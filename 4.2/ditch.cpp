/*
ID: billy
PROG: ditch
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
std::ifstream in("ditch.in");
std::ofstream out("ditch.out");
int M;

int con[201][201];
int parent[201];

void print(){
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= M; j++){
            cout << con[i][j] << ' ';
        }
        cout << endl;
    }
        cout << endl;
}

bool bfs(){
    memset(parent,-1,sizeof(parent));
    parent[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        if(tmp == M) return true;
 //       cout << tmp << endl;
        for(int i = 1; i <= M; i++){
            if(con[tmp][i] > 0 && parent[i] == -1){
                parent[i] = tmp;
                q.push(i);
            }
        }
    }
    return false;
}

int maxflow(){
    int flow = 0;
    int pathflow;   
    while(bfs()){
        pathflow = INT_MAX;
        int i = M;
        while(i != parent[i]){
            pathflow = min(pathflow,con[parent[i]][i]);
            i = parent[i];
        }
        i = M;
        while(i != parent[i]){
            con[parent[i]][i] -= pathflow;
            con[i][parent[i]] += pathflow;
            i = parent[i];
        }
        flow += pathflow;
//        cout << pathflow << endl;
    }
    return flow;
}

int main(){
    int N;
    in >> N >> M;

    for(int i = 0; i < N; i++){
        int a,b,c;
        in >> a >> b >> c;
        con[a][b] += c;
    }
//    print();
    

    out << maxflow() << endl;
}
