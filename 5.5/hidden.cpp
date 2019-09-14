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
int ar[100000];

bool cmp(int a, int b){
    return strncmp(s.c_str()+a,s.c_str()+b,L) < 0;
}

void hidden(){
    for(int i = 0; i < L; i++){
        ar[i] = i;
    }

    sort(ar,ar+L,cmp);
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
    out << ar[0] << endl; 
}
