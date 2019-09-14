/*
ID: billyz43
PROG: hidden
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;
std::ifstream in("hidden.in");
std::ofstream out("hidden.out");

int L;
string s;
char sm = 127;
int a,b;

void hidden(){
    for(int i = 0; i < L; i++){
        if(s[i] < sm){
            sm = s[i];
            a = i;
        }
        if(sm == 'a') break;
    }
//    cout << "sm " << sm << " a " << a << endl;

    for(b = a+1; b < L; b++){
        if(s[b] == sm){
  //          cout << "b " << b << endl;
            int i = 0;
            for(; i < L && s[b+i] == s[a+i]; i++){
            }
    //        cout << "i " << i << endl;
            if(i == L) break;
            if(s[a+i] > s[b+i]) a = b;
            else b = b+i; 
        }
    }
    out << a << endl;
}

int main(){
    string a;
    in >> L;
    int line = L;
    while(line > 0){
        in >> a;
        s += a;
        line -= 72;
    }
    s += s;
    hidden();
}
