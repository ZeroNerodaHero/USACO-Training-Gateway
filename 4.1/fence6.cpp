/*
ID: billyz43
PROG: fence6
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
std::ifstream in("fence6.in");
std::ofstream out("fence6.out");
int N; 

struct seg{
    int w;
    set<int> l,r;
};

struct path{
    int e, w;
    path(int e, int w): e(e),w(w) {};
    bool operator <(const path& o) const{
        return w > o.w;
    }
};

seg f[101];
int ans = 0x7F7F7F7F;
bool visited[101];
int weight[101];

void print(){
    for(int i = 1; i <= N; i++){
        cout << i << " " <<f[i].w << endl;
        cout << "Left: ";
        for(auto it:f[i].l){
            cout << it << ' ';
        } cout << endl;
        cout << "Right: ";
        for(auto it:f[i].r){
            cout << it << ' ';
        } cout << endl;
        cout  << endl;
    }
}

void dijk(int e){
    memset(weight,0x7F,sizeof(weight));
    memset(visited,0,sizeof(visited));
    priority_queue<path> q;
    for(auto i: f[e].l){
        q.push(path(i,f[i].w+f[e].w));
    }   
    while(!q.empty()){
        path tmp = q.top();
        q.pop();

        if(visited[tmp.e]) continue;

        visited[tmp.e] = true;
        for(auto i:f[tmp.e].l){
            if(i == e){
                if(f[i].r.find(tmp.e) != f[i].r.end()){
                    ans = min(ans,tmp.w);
                    return;
                }
                continue;
            }
            if(!visited[i] && tmp.w+f[i].w < weight[i]){
                weight[i] = tmp.w+f[i].w;
                q.push(path(i,weight[i]));
            }
        } 

        for(auto i:f[tmp.e].r){
            if(i == e){
                if(f[i].r.find(tmp.e) != f[i].r.end()){
                    ans = min(ans,tmp.w);
                    return;
                }
                continue;
            }
            if(!visited[i] && tmp.w+f[i].w < weight[i]){
                weight[i] = tmp.w+f[i].w;
                q.push(path(i,weight[i]));
            }
        }        
    }
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        int s,n1,n2;
        int a;
        in >> s;
        in >> f[s].w >> n1 >> n2;
        for(int j = 0; j < n1; j++){
            in >> a;
            f[s].l.insert(a);
        }
        for(int j = 0; j < n2; j++){
            in >> a;
            f[s].r.insert(a);
        }
    }
    //print();
    for(int i = 1; i <= N; i++){
        dijk(i);
    }
    out << ans << endl;
}
