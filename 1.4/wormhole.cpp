/*
ID: NomNom
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int N;
int a[12];

struct point{
    int x, y;
    //point(int x,int y): x(x), y(y) {};
    bool operator <(const point &o) const{
        if(y == o.y) return x < o.x;
        return y < o.y;
    }
};

point p[12];

void print(){
    for(int i = 0; i < N; i++){
        cout << a[i] << ' ';
    } cout << endl;
}

int index(int i){
    for(int j = 0; j < N; j++){
        if(a[j] == i) return j;
    }
    return 0;
}

bool loop(int p1, int count){
    if(count > N) return true;
    if(p1 == N-1) return false;
    int p0 = p1+1;
    if(p[p0].y != p[p1].y){
        return false;
    }
    int i = index(p0);
    if(i & 1){
        p1 = a[i-1];
    } else{
        p1 = a[i+1];
    }
    return loop(p1,count+1);
}

bool iscycle(){
    for(int i = 0; i < N; i++){
        int p1;
        if(i & 1){
            p1 = a[i-1];
        } else{
            p1 = a[i+1];
        }
        if(loop(p1,0)){
            return true;
        }
    }    
    return false;
}   

int perm(int i){
    static int count = 0;
    if(i == N){
        if(iscycle()){
            count++;
        } 
    }
    for(int j = i+1; j < N; j++){
        swap(a[i+1],a[j]);
        perm(i+2);
        swap(a[i+1],a[j]);
    }
    return count;    
}

int main(){
    ifstream in("wormhole.in");
    ofstream out("wormhole.out");

    in >> N;
    for(int i = 0; i < N; i++){
        in >> p[i].x >> p[i].y;
        a[i] = i;
    }
    sort(p,p+N);
    out << perm(0) << endl;;
    return 0;   
}
