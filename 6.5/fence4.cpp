/*
ID: billyz43
PROG: fence4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
std::ifstream in("fence4.in");
std::ofstream out("fence4.out");
struct point{
    double x, y;
    point() {};
    point(double x, double y): x(x),y(y) {}
};
struct seg{
    int a,b;
    seg(int a,int b):a(a),b(b) {}
    seg() {}
    bool operator <(const seg& o) const{
        if(o.b == b) return a < o.a;
        return b < o.b;
    }
};

int N;
point pt[205];
bool see[205];
int vx,vy;
void print(){
    for(int i = 0; i <= N; i++){
        cout << pt[i].x << ' ' << pt[i].y << endl;
    }
}
vector<seg> ans;

bool flag = false;
int ccw(point& a, point& b, point& c){
    double t = (c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x);
/*
if(flag) {
    cout << "t: " << t << endl;
    cout << "ccw: " << ((c.y-b.y)*(b.x-a.x) - (b.y-a.y)*(c.x-b.x)) << endl;
}
*/
    if(t > 0) return 1;
    if(t < 0) return -1;
    return t;
}

bool bet(point p1,point p2, point p3){
    if(p1.x != p2.x) return (p3.x >= min(p2.x,p1.x)) && (p3.x <= max(p1.x,p2.x));
    return (p3.y >= min(p2.y,p1.y)) && (p3.y <= max(p1.y,p2.y));
}

bool crossing(point& p1, point& p2, point& p3, point& p4){
    int a = ccw(p1,p2,p3);
    int b = ccw(p1,p2,p4);
    int c = ccw(p3,p4,p1);
    int d = ccw(p3,p4,p2);
    if((a == 0 && bet(p1,p2,p3)) ||
       (b == 0 && bet(p1,p2,p4)) ||
       (c == 0 && bet(p3,p4,p1)) ||
       (d == 0 && bet(p3,p4,p2)) ||
       ((a != b) && (c !=d))){
            return true;
    }
    if(flag){
        cout << a << endl;
    }
    return false;
}

bool crossing(int i, int j){
    return crossing(pt[i],pt[i+1],pt[j],pt[j+1]);
}
bool isV(){
    for(int i = 2; i < N; i++){
        int j = 0;
        if(i == N-1) j++;
        for(; j < i-1; j++){
            if(crossing(j,i)){
//                cout << i << ' ' << j << endl;
//                cout << pt[i].x << ' ' << pt[i].y << ' ' << pt[i+1].x << ' ' << pt[i+1].y << endl;
//                cout << pt[j].x << ' ' << pt[j].y << ' ' << pt[j+1].x << ' ' << pt[j+1].y << endl;
                out << "NOFENCE\n";
                return false;
            }
        }
    }
    return true;
}

bool cansee(point p,int pos,bool vert=0){
    point v = point(vx,vy);
    for(int i = 0; i < N; i++){
        if(i == pos) continue;
        if(vert){
            if(pos == 0 && i == N-1) continue;
            if(i == pos-1) continue;
        }
//if (pos==0&&!vert&&i==11) flag = true;
        if(crossing(v,p,pt[i],pt[i+1])){
            return false;
        }
//flag = false;
    }   
    return true;
}

double dist(point a, point b){
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y)); 
}

bool view(int c){
    point l = pt[c];
    point r = pt[c+1];
    if(see[c+1]){
        l = pt[c+1];
        r = pt[c];
    }
    
    while(dist(l,r) > 0.01){
        point mid;
        mid.x = (l.x + r.x)/2;
        mid.y = (l.y + r.y)/2;
        if(cansee(mid,c)) return true; 
        r = mid;   
    }
    return false;
}

void view(){
    point v = point(vx,vy);
    see[0] = cansee(pt[0],0,1);
    for(int i = 0; i < N; i++){
        if(ccw(v,pt[i],pt[i+1]) == 0){
            continue;
        }
        if(i+1 == N) see[i+1] = see[0];
        else see[i+1] = cansee(pt[i+1],i+1,1);
#if 0
        if((see[i] && see[i+1]) || (view(i))){
            if(i == N-1){
                ans.push_back(seg(0,i));
            } else ans.push_back(seg(i,i+1));
        } 
#else

        if((see[i] && see[i+1])){
            point m = point((pt[i].x + pt[i+1].x)/2,(pt[i].y + pt[i+1].y)/2);
//            cout << i << ' ' << i+1 << endl;
//            cout << m.x << ' ' << m.y << endl;
            if(cansee(m,i)){
                if(i == N-1){
                    ans.push_back(seg(0,i));
                } else ans.push_back(seg(i,i+1));
            }
        } 
        else if((view(i))){
            if(i == N-1){
                ans.push_back(seg(0,i));
            } else ans.push_back(seg(i,i+1));
        } 
#endif
        
    }
}

void printa(){
    sort(ans.begin(),ans.end());
    out << ans.size() << endl;
    for(auto& i: ans){
        out << pt[i.a].x << ' ' << pt[i.a].y << ' ';
        out << pt[i.b].x << ' ' << pt[i.b].y << endl;
    }
}

int main(){
    in >> N;
    in >> vx >> vy;
    for(int i = 0; i < N; i++){
        in >> pt[i].x >> pt[i].y;
    }
    pt[N] = pt[0];
    //print();
    if(!isV()) return 0;
    view();
    printa();
}
