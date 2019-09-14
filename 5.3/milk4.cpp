/*
ID: billyz43
PROG: milk4
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <utility>
using namespace std;
std::ifstream in("milk4.in");
std::ofstream out("milk4.out");

int Q;
int P;
int t[100];
bool c[100];

void print1(){
    for(int i = 0; i < P; i++){
        cout << c[i] << ' ';   
    }
    cout << endl;
}
void combo(int s, int e){
    if(e == 0){
        for(int i = 0; i < P; i++){
            if(c[i]) cout << t[i] << ' ';
        }
        cout << endl;
//        print1();
        return;
    } 
    if(s == P) return;
    c[s] = true;
    combo(s+1,e-1);
    c[s] = false;
    combo(s+1,e);
}

void print(){
    for(int i = 0; i < P; i++){
        cout << t[i] << ' ';   
    }
    cout << endl;
}
int main(){
    in >> Q >> P;
    for(int i = 0; i < P; i++){
        in >> t[i];
    }
    sort(t,t+P);
    print();
    for(int i = 1; i <= P; i++){
       combo(0,i);
    }
}
