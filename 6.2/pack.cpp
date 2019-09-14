/*
ID: billyz43
PROG: packrec
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("packrec.in");
std::ofstream out("packrec.out");
int total = 0;
int w[4],h[4];
int ar[4] = {0,1,2,3};;
int sm = 999999; 

struct rect{
    int p,q;
    rect() {};
    rect(int a, int b){
        p = min(a,b);
        q = max(a,b);
    }
    bool operator< (const rect& o) const{
        return p < o.p;
    }
};

vector<rect> v;
void Record(int x, int y){
    int area = x * y;
    if(area > sm) return;
    if(area < sm){
        sm = area;
        v.clear();
    }
    v.push_back(rect(x,y));
}

#if 0
#define record(x, y) do {\
        xxx++;\
        if(x*y==80) {\
        cout << "xxx " << xxx << endl;\
        }\
        Record(x,y);\
    } while(0)
#else
#define record(x,y) Record(x,y)
#endif


void pack(int a, int b, int c, int d){
    int xxx=0;
    int x,y;
    y = max(max(h[a],h[b]),max(h[c],h[d]));
    x = w[a] + w[b] + w[c] + w[d];
    record(x,y);

    y = w[a] + max(max(h[c],h[d]),h[b]);
    x = max(h[a],w[c]+w[d]+w[b]);
    record(x,y);

    y = max(h[a]+max(h[b],h[c]),h[d]);
    x = max(w[a],w[b]+w[c])+w[d];
    record(x,y);

    x = w[a] + max(w[b],w[c])+w[d];
    y = max(h[a],max(h[b]+h[c],h[d]));
    record(x,y);

    x = max(w[a],w[b]) + w[c] + w[d];
    y = max(h[a]+h[b],max(h[c],h[d]));
    record(x,y);

    x = max(w[a],w[b])+max(w[c],w[d]);
    y = max(h[a]+h[b],h[c]+h[d]);   
    if(h[c] >= h[a] && w[b] <= w[a]){
        x = min(x, max(w[a]+w[c],w[b]+w[d]));
    }
    if(h[c] >= h[a]+h[b]){
        x = min(x,max(max(w[a],w[b])+w[c],w[d]));
    }
    record(x,y);
}

void print(){
    cout << ++total << ' ';
    for(int i = 0; i < 4; i++){
        cout << ar[i] << ' ';
    }
    cout << endl;
}

void rot(int i){
    if(i == 4){
        pack(ar[0],ar[1],ar[2],ar[3]);
        return;
    }
    rot(i+1);
    if(w[i] != h[i]){
        swap(w[i],h[i]);
        rot(i+1);
    }
}

void dfs(int l){
//    cout << "l " << l << endl;
    if(l == 4){
//        print();
        rot(0);
        return;
    } 
    for(int i = l; i < 4; i++){
//        cout << '\t' << l << ' '<< i << endl;
        swap(ar[i],ar[l]);
        dfs(l+1);
        swap(ar[i],ar[l]);
    }
}

int main(){
    for(int i = 0; i < 4; i++){
        in >> w[i] >> h[i];
//        cout << w[i] << ' ' << h[i] << endl;
    }
    dfs(0); 
    sort(v.begin(),v.end());
    out << v[0].p * v[0].q << endl;
    out << v[0].p << ' ' << v[0].q << endl;
    for(int i = 1; i < v.size(); i++){
        if(v[i].p == v[i-1].p) continue;
        out << v[i].p << ' ' << v[i].q << endl;
    }
    return 0;
}
