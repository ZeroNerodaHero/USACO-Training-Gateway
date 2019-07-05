/*
ID: billy
PROG: telecow
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define INF 2000
using namespace std;
std::ifstream in("telecow.in");
std::ofstream out("telecow.out");
int N, M, c1, c2;
int adj[201][202];
int p[202];

void print(){
    for(int i = 1; i <= 2*N; i++){
        for(int j = 1; j <= 2*N; j++){
            cout.width(5);
            cout << adj[i][j];
        }
        cout << endl;
    }
}

void m1(int s, int t){
    bool v[2*N+1];
    memset(v,0,sizeof(v));
    
    queue<int> q;
    q.push(s);
    v[s] = true;

    while(!q.empty()){
        int tmp = q.front();
        q.pop();

        for(int i = 1; i <= 2*N; i++){
            if(adj[tmp][i] && !v[i]){
                v[i] = true;
                q.push(i);   
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(v[i] && !v[i+N]){
            out << ' ' << i ;
        }
    } 
}

bool bfs(int s, int t){
 //   cout << "bfs " << s << ' ' << t << endl;
    memset(p,-1,sizeof(p));
    queue<int> q;
    q.push(s);
    p[s] = 0;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();


        for(int i = 1; i <= 2*N; i++){
            if(adj[u][i] > 0 && p[i] == -1){
                p[i] = u;
                if(i == t){
                    return true;
                }
                q.push(i);
            }            
        } 
    }
 //   cout << "bfs false" << endl;
    return false;
}

int flow(int s, int t){
    int flow = 0;
    while(bfs(s,t)){
      //  cout << s << ' ' << t << "\ttrue" << endl;
        int tmp = t;
        while(p[tmp] != 0){
//            if(p[tmp] == tmp-N) cout << tmp-N << ' ';
            adj[p[tmp]][tmp] -= 1;
            adj[tmp][p[tmp]] += 1;
            tmp = p[tmp];
        }
//        cout << endl;
        flow++;
    }
    return flow;
}

int mincut(int s, int t, int f){
    vector<int> c;
    for(int i = 1; i <= N && f > 0; i++){
        if(i == s || i == t) continue;
        for(int j = 1; j <= N; j++){
            if(j != c1 && j != c2){
                adj[j][j+N] = 1;
                adj[j+N][j] = 1;
            }
        }
        
        for(auto& j: c){
            adj[j][j+N] = 0;
            adj[j+N][j] = 0;
        }
        adj[i][i+N] = 0;
        adj[i+N][i] = 0;
        int cflow = flow(s,t);
//        cout << i << " cflow " << cflow << endl;
        if(cflow < f){
            c.push_back(i);
            f--;
        }
    }
    for(auto& i: c){
        if(i != c[0]){
            out << ' ';
        }
        out << i;
    }
    out << endl;
}

int main(){
    in >> N >> M >> c1 >> c2;
    
    for(int i = 0; i < M; i++){
        int a,b;
        in >> a >> b;
     //   cout << a << ' ' << b << endl;
        adj[a+N][b] = INF;
        adj[b+N][a] = INF;
    }

    for(int i = 1; i <= N; i++){
        if(i != c1 && i != c2){
            adj[i][i+N] = 1;
            adj[i+N][i] = 1;
        }
    }
    //cout << "inputs" << endl;
    int s = c1+N, t = c2;
//    print();
    int fl = flow(s,t);
    out << fl << endl;
    mincut(s,t,fl);
  //  print();
}
