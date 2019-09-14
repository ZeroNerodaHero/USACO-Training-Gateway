/*
ID: billyz43
PROG: fence3
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iomanip>
#include <cmath>
using namespace std;
std::ifstream in("fence3.in");
std::ofstream out("fence3.out");

struct line{
    double l,r,h;
    bool x;
};
line ln[150];
int F;
double rx,ry,d;
double mx0,mx1,my0,my1;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
//int dx[8] = {-1,-1,-1,0,0,1,1,1};
//int dy[8] = {-1,0,1,-1,1,-1,0,1};


double dist(double x, double y, int i){
    if(ln[i].x){
        double dy = (ln[i].h-y);
//        cout << "hor " << dy << endl;
        if(x >= ln[i].l && x <= ln[i].r){
            return abs(dy);    
        } 
        else if(x > ln[i].r){
            return sqrt((ln[i].r-x)*(ln[i].r-x)+dy*dy);
        }
        else{ 
            return sqrt((ln[i].l-x)*(ln[i].l-x)+dy*dy);
        }
    } else{
        double dx = (ln[i].h-x);
  //      cout << "ver " << dx << endl;
        if(y <= ln[i].r && y >= ln[i].l){
            return abs(dx);
        }
        else if(y > ln[i].r){
            return sqrt(dx*dx + (ln[i].r-y)*(ln[i].r-y));
        }
        else{
            return sqrt(dx*dx + (ln[i].l-y)*(ln[i].l-y));
        }
    }
        
}
double dist(double x, double y){
    double res = 0;
    for(int i = 0; i < F; i++){
        res += dist(x,y,i);
    }
//        cout << x << " "<< y << " : "<<res << endl;
    return res;
}
double s = 10;

int times=1;
bool dfs(double s){
//    cout << times++<< ": " <<s << ", " << rx << ' ' << ry << ' ' << d<< endl;
    double ret;
    for(int i = 0; i < 4; i++){
        double nx = rx+dx[i] * s;
        double ny = ry+dy[i] * s;

//if (s<5) cout << nx << " " << ny << endl;
        
        if(nx >= mx0  && nx <= mx1 && ny >= my0 && ny <= my1){
            ret = dist(nx,ny);
//if (s<5) cout << nx << " " << ny << " dist " << ret << endl;
            if(ret < d){
                d = ret;
                rx = nx;
                ry = ny;
 //               dfs(s);
                return true;
            }
        }
    }    
    return false;
}

int main(){
    in >> F;
    for(int i = 0; i < F; i++){
        double a,b,c,d;
        in >> a>> b >> c >> d;
        mx0 = min(mx0,min(a,c));
        mx1 = max(mx1,max(a,c));
        my0 = min(my0,min(b,d));
        my1 = max(my1,max(b,d));
        if(a != c){
            ln[i].l = min(a,c);
            ln[i].r = max(a,c);
            ln[i].h = b;          
            ln[i].x = true;
        } else{
            ln[i].l = min(b,d);
            ln[i].r = max(b,d);
            ln[i].h = a;
            ln[i].x = false;
        }
    }
//    cout << dist(1,2) << endl;;
//    cout << mx0 << ' ' <<  my0 << '\t' << mx1 << ' ' << my1 << endl;
    rx = (mx0 + mx1)/2;
    ry = (my0 + my1)/2;
    //rx = ry = 50; mx0 = my0 = 0; mx1 = my1 = 100;
    d = dist(rx,ry);
    for(int i = 0; i < 3; i++){
        while(dfs(s)) {}
        s /=10;       
    }
    out << fixed;
    out << setprecision(1) << rx << ' ' << ry << ' ' << d << endl;
}

/*
USER: Billy Zhang [billyz43z43]
TASK: fence3
LANG: C++11

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.004 secs, 1312 KB]
   Test 2: TEST OK [0.004 secs, 1380 KB]
   Test 3: TEST OK [0.004 secs, 1308 KB]
   Test 4: TEST OK [0.000 secs, 1316 KB]
   Test 5: TEST OK [0.004 secs, 1324 KB]
   Test 6: TEST OK [0.004 secs, 1316 KB]
   Test 7: TEST OK [0.004 secs, 1312 KB]
   Test 8: TEST OK [0.004 secs, 1320 KB]
   Test 9: TEST OK [0.004 secs, 1320 KB]
   Test 10: TEST OK [0.004 secs, 1312 KB]
   Test 11: TEST OK [0.004 secs, 1312 KB]
   Test 12: TEST OK [0.004 secs, 1308 KB]
*/
