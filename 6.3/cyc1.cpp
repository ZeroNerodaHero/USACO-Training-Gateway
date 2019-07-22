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
int F,R,T,f1,f2,r1,r2;

char fc[15],ansf[15];
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
        for(int j = F; j < T; j++){
            rats[c++] = double(fc[i])/double(fc[j]); 
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
        for(int i = 0; i < T; i++){
            ansf[i] = fc[i];
        }
    }
}

void rear(int c, int i){
    if(c == T){
        if(fc[0] * fc[F] * 3 > fc[F-1] * fc[T-1]){
//            cout  << int(fc[0] ) << "-" << int(fc[F]) << '\t' << int( fc[F-1] ) << '-' << int(fc[T-1]) << endl;
            
            return;;
        }
//            cout << "ratio\t";
//            print();
            var();
            calc();
        return;
    }
    for(; i <= r2; i++){
        fc[c] = i;
        rear(c+1,i+1);
    }
}

void front(int c, int i){
    if(c == F){
        rear(c,r1);
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
    T = F+R;

    front(0,f1);
    out << int(ansf[0]);
    for(int i = 1; i < F; i++){
        out << ' ' <<int(ansf[i]);
    }
    out << endl <<  int(ansf[F]);
    for(int i = F+1; i < T; i++){
        out << ' ' <<int(ansf[i]);
    }   
    out << endl;
}
