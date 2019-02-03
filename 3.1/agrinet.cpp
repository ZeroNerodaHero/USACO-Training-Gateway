/*
ID: billy
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;
std::ifstream in("agrinet.in");
std::ofstream out("agrinet.out");

struct node{
    int cur, d;
    node(int cur,int d): cur(cur),d(d) {}
    bool operator <(const node &o) const{
        return d > o.d;
    }
};

int main(){
    int N;
    in >> N;
    int con[100][100];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> con[i][j];
        }
    }

    bool visited[N];
    int weight[N];
    int sum = 0,edge = 1;
    memset(visited,0,sizeof(visited));
    memset(weight,0x1F,sizeof(weight));
    priority_queue<node> q;
    visited[0] = true;
//    int m = 1;
    for(int i = 1; i < N; i++){
        weight[i] = con[0][i];
        q.push(node(i,con[0][i]));
        //if(con[0][m]>con[0][i]) m = i;
    }
    //q.push(node(0,m,con[0][m]);

    while(!q.empty()){
//    while(edge  < N){
        node tmp = q.top();
        q.pop();
        int u = tmp.cur;
//        cout << edge << endl;
        if(visited[u]) continue;
        edge++;
        visited[u] = true;
        sum += tmp.d;

        for(int i = 0; i < N; i++){
            //if((!visited[i])&&(con[u][i] < weight[i])){ 
            if(!visited[i]){ 
                weight[i] = con[u][i];
                q.push(node(i,con[u][i]));
            }
        }
    }
    out << sum << endl;
}
