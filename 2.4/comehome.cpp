/*
ID: billyz43
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
std::ifstream in("comehome.in");
std::ofstream out("comehome.out");

int dist[52][52];
int visited[52];

struct pos{
    int cur, dist;
    pos(int cur, int dist):
        cur(cur),dist(dist) {} 
    bool operator<(const pos& o) const{
        return dist > o.dist;
    }
};

void print(){
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int P;
    in >> P;
    
    for(int i = 0; i < P; i++){
        char s, e;
        int cdist;
        in >> s >> e >> cdist;
//        cout << s << ' ' <<  e << endl;
        int ts, te;
        if(s < 'a'){
            ts = s-'A';
        } else {
            ts = (s-'a')+26;
        }
        if(e < 'a'){
            te = e-'A';
        } else{
            te = (e-'a')+26;
        }
//        cout << ts << ' ' <<  te << ' ' << cdist << endl;
        if(dist[ts][te] == 0) dist[ts][te] = cdist;
        else dist[ts][te] = min(dist[ts][te],cdist);
        dist[te][ts] = dist[ts][te];
    }
//    print();
    priority_queue<pos> q;
    for(int i = 0; i < 52; i++){
        if(dist[25][i] > 0){
//                cout << dist[25][i] << endl;
            q.push(pos(i,dist[25][i]));
        }
    }
    visited[25] = true;
    while(!q.empty()){
        pos tmp = q.top();
        q.pop();
  //      cout << "cur " <<tmp.cur << ' ' << tmp.dist << endl;
        if(visited[tmp.cur]) continue;
        visited[tmp.cur] = true;
        if(tmp.cur < 25){
            out << char('A'+tmp.cur) << ' ' << tmp.dist << endl;
            return 0;
        }
        for(int i = 0; i < 52; i++){
 //           if(dist[tmp.cur][i] > 0) cout << dist[tmp.cur][i] << ' ' << visited[i]<< endl;
            if((!visited[i]) && (dist[tmp.cur][i] > 0)){
   //             cout << dist[tmp.cur][i] << endl;
                q.push(pos(i,dist[tmp.cur][i]+tmp.dist)); 
            }
        }
    }
}
