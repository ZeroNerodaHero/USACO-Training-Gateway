/*
ID: billy
PROG: butter
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 0x7F7F7F7F
using namespace std;
std::ifstream in("butter.in");
std::ofstream out("butter.out");
    
struct node{
    int d, w;
    node(int d, int w):d(d),w(w) {}
    bool operator <(const node &o) const{
        return w > o.w;
    }
};

vector<node> g[805];
int cows[805];
int N,P,C;

void print(int ar[]){
    for(int i = 1; i <= P; i++){
        cout << ar[i] << ' ';
    } cout << endl;
}

int dijk(int st){
    bool visited[805];
    memset(visited,0,sizeof(visited));
    int dist[805];
    memset(dist,0x7F,sizeof(dist));
    dist[st] = 0;
    priority_queue<node> q;
    q.push(node(st,0));

    while(!q.empty()){
        node tmp = q.top();
        q.pop();
                
        int a = tmp.d, b = tmp.w;
        //cout << "proccess " << a << endl;
        if(visited[a]) continue;
        visited[a] = true;
        for(auto &i:g[a]){
            if(!visited[i.d] && dist[a] + i.w < dist[i.d]){
                dist[i.d] = dist[a] + i.w;
                //cout << i.d << " " << dist[i.d] << endl;
                q.push(node(i.d,dist[i.d]));
            }
        }
    }
    //print(dist);
    int t = 0;
    for(int i = 0; i < N; i++){
        //cout << cows[i] << endl;
        t += dist[cows[i]]; 
    }
    //cout << "t is " << t << endl;
    return t;
}

int main(){
    in >> N >> P >> C;
    for(int  i = 0; i < N; i++){
        in >> cows[i];
    }
    for(int i = 0; i < C; i++){
        int a,b,c;
        in >> a >> b >> c;

        g[a].push_back(node(b,c));
        g[b].push_back(node(a,c));
    }
    int small = INF;
    for(int i = 1; i <= P; i++){
        small = min(small,dijk(i));
    }
    out << small << endl;
    return 0;
}

