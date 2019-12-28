/*
ID: billyz43
PROG: around
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
#include <list>
std::ifstream in("around.in");
std::ofstream out("around.out");
using namespace std;
struct P{
    int pos,cnt,deg;
    P(int pos, int cnt, int deg): 
        pos(pos),cnt(cnt),deg(deg) {};
    bool operator < (const P& o) const{
        return cnt > o.cnt;
    }
};
list<int> fl[5001];
int deg[5001];
int N, M;

//bool vc[5001],vcc[5001];
int v[5001];
int bfs(){
    bool fir = true;
    priority_queue<P> q;
    q.push(P(1,0,0));
    int dc[5001],dcc[5001];
    memset(dc,0x3f,sizeof(dc));
    memset(dcc,0x3f,sizeof(dcc));
    
    while(!q.empty()){
        P tmp = q.top();
        q.pop();
        cout << tmp.pos << ' ' << tmp.deg << ' '<< tmp.cnt << endl;
    
        if(tmp.pos == 1){
            if(tmp.deg != 0)
                return tmp.cnt;
            else if(fir){
                fir = false;
            } else{
                continue;
            }
        }
        
        if(abs(tmp.deg) >= 360){
            
            return tmp.cnt * 2;
        }

        for(auto i : fl[tmp.pos]){
            int d = deg[i]-deg[tmp.pos];
            if(abs(d) > 180){
                if(d < 0) d+= 360;
                else d-= 360;
            }

            d += tmp.deg;
            if(i == 1){
                q.push(P(i,tmp.cnt+1,d));
            } else{
            if(d >= 0 && dc[i] > tmp.cnt+1){
                dc[i] = tmp.cnt+1;
                q.push(P(i,tmp.cnt+1,d));
            }
            if(d <= 0 && dcc[i] > tmp.cnt+1){
                dcc[i] = tmp.cnt+1;
                q.push(P(i,tmp.cnt+1,d));
            }   
            }
        }
    }
    return -1;
}

int main(){
    in >> N >> M;
    for(int i = 1; i <= N; i++){
        in >> deg[i];   
    }

    for(int i = 0; i < M; i++){
        int a,b;
        in >> a >> b;
        fl[a].push_back(b);
        fl[b].push_back(a);
        v[a]++;
        v[b]++;
    }
    int ans = bfs();
    out << ans << endl;;
}
