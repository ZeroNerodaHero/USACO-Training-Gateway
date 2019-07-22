/*
ID: billy
PROG: rect1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("rect1.in");
std::ofstream out("rect1.out");
map<int,int> m;
int A, B, N;

struct rect{
    int id, lx,ly,tx,ty;

    rect() {};
    rect(int id, int lx, int ly, int tx, int ty):
        id(id),lx(lx),ly(ly),tx(tx),ty(ty) {}
};
list<rect> v;

void over(rect& a, rect& b){
    if(a.lx < b.lx){
        int ctx = min(b.lx,a.tx);
        v.push_back(rect(a.id,a.lx,a.ly,ctx,a.ty));
    }
    if(a.tx > b.tx){
        int clx = max(a.lx,b.tx);
        v.push_back(rect(a.id,clx,a.ly,a.tx,a.ty));
    }
    int lx = max(a.lx,b.lx);
    int tx = min(a.tx,b.tx);
    if(lx < tx){
        if(a.ly < b.ly){
            int ty = min(a.ty,b.ly);
            v.push_back(rect(a.id,lx,a.ly,tx,ty));
        }
        if(a.ty > b.ty){
            int ly = max(a.ly,b.ty);
            v.push_back(rect(a.id,lx,ly,tx,a.ty));
        }
    }
}

void split(rect& cur){
    int n = v.size();
    while(n > 0){
        over(v.front(),cur); 
        v.pop_front();
        n--;
    }
}

void area(){
    int total = A * B;
    for(auto& i: v){
        int are = (i.tx-i.lx)*(i.ty-i.ly);
        m[i.id] += are;
        total -= are;
    }
    m[1] += total;
    for(auto& i: m){
        out << i.first << ' ' << i.second << endl;
    }
}


int main(){
    in >> A >> B >> N;
    for(int i = 0; i < N; i++){
        int lx, lly, urx, ury, c;
        in >>  lx>> lly>> urx>> ury>> c;
        rect cur = rect(c,lx, lly, urx, ury); 
        split(cur);
        v.push_back(cur);
    }
    area();
    
    return 0;
}
