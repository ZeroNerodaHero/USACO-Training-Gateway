/*
ID: billy
PROG: cowcycle
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
std::ifstream in("cowcycle.in");
std::ofstream out("cowcycle.out");
int F,R,f1,f2,r1,r2;

int fc[5],ansf[5];
int rc[10],ansr[10];
int ft,rt,ti,tot;
double ansv = 10000;
double rats[50];

void print(){
    for(int i = 0; i < F*R; i++){
        cout << rats[i] <<  ' ';
    }
    cout << endl;
}

void var(){
    int c = 0;
    for(int i = 0; i < F; i++){
        for(int j = 0; j < R; j++){
            rats[c++] = double(fc[i])/double(rc[j]); 
        }
    }
//    print();
    sort(rats,rats+R*F);
}

void calc(){
    double m = rats[F*R-1]-rats[0];
    m /= F*R-1;
    double t = 0;
    for(int i = 0; i < F*R-1; i++){
        rats[i] = rats[i+1] -rats[i];   
        t += (rats[i]-m)*(rats[i]-m);
    } 
    t /= F*R-1;
    
//    cout << t << endl;
    if(t < ansv){
        ansv = t;
        for(int i = 0; i < F; i++){
            ansf[i] = fc[i];
        }        
        for(int i = 0; i < R; i++){
            ansr[i] = rc[i];
        }        
    }
}

void rear(int c, int i){
    if(c == R){
 //       tot++;
        if(fc[0] * rc[0] * 3 > fc[F-1] * rc[R-1]){
   //         ti++;
//            cout << fc[0] * rc[0] << "sm - l " << fc[F-1] * rc[R-1] << endl;
            return;;
        }
//            cout << "ratio\t";
//            print();
            var();
            calc();
        return;
    }
    for(; i <= r2; i++){
        rc[c] = i;
        rear(c+1,i+1);
    }
}

void front(int c, int i){
    if(c == F){
        rear(0,r1);
        return;
    }
    for(; i <= f2; i++){
        fc[c] = i;
        front(c+1,i+1);
    }
}

int main(){
    in >> F >> R;
    in >> f1 >>f2 >> r1 >> r2;

    front(0,f1);
    out << ansf[0];
    for(int i = 1; i < F; i++){
        out << ' ' <<ansf[i];
    }
//    cout << ti << endl;
//    cout << tot << endl;
    out << endl <<  ansr[0];
    for(int i = 1; i < R; i++){
        out << ' ' <<ansr[i];
    }   
    out << endl;
}
