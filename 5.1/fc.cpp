/*
ID: billy
PROG: fc
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
std::ifstream in("fc.in");
std::ofstream out("fc.out");
int N;

struct point{
    double x,y;
};
point pt[10001];

void print(){
    for(int i = 0; i < N; i++){
        cout << pt[i].x << ' ' << pt[i].y << endl;
    }
}

int ccw(point& a,point& b,point& c){
    double pd2 = (c.y-b.y) * (b.x-a.x);
    double pd1 = (b.y-a.y) * (c.x-b.x); 
    if(pd2 > pd1) return 1;
    else if(pd2 < pd1) return -1;
    return 0;
}
double dist(point& a, point&b) {
    return sqrt((b.y-a.y) * (b.y-a.y) + (b.x-a.x) * (b.x-a.x));
}
point f;
bool cmp(point& b, point& c) {
    int isccw = ccw(f,b,c);
    if(isccw > 0) return true;
    if(isccw == 0) return dist(f,b) < dist(f,c);
    return false;
}

void graham(){
    point p[N];
    int s = 0;
    for(int i = 1; i < N; i++){
        if(pt[i].x < pt[s].x || (pt[i].x == pt[s].x && pt[i].y < pt[s].y)){
            s = i;
        }
    }

    f = pt[s];
    swap(pt[s],pt[0]);
    sort(pt+1,pt+N,cmp);
    
    p[0] = pt[0];
    p[1] = pt[1];
    int c = 1;

    for(int i = 2; i < N; i++){
        while(c > 0 && ccw(p[c-1],p[c],pt[i]) <= 0){
            c--;
        }
        c++;
        p[c] = pt[i];
    }   

    double d = dist(p[0],p[c]);;   
    for(int i = 0; i < c; i++){
        d += dist(p[i],p[i+1]);
    }
    out << fixed <<  setprecision(2) << d << endl;
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> pt[i].x >>pt[i].y;
    }

    graham();
}
