/*
ID: billy
PROG: fence9
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
std::ifstream in("fence9.in");
std::ofstream out("fence9.out");

int n,m,p;

int main(){
    in >> n >> m >> p;
    int ex = p-n;
    
    int b = (m/ex)*(p);
    //cout << ex << ' ' << b << endl;
    
    int total = 0;
    for(int i = 1; i < m; i++){
        int y = i*n;
        int o1 = y/m + 1;
        int o2 = (i*(ex)/m);
        if (ex <0) {
            if(o2*m == i*ex) o2++;
        } else o2++;
//        cout << float(i*ex)/m << endl;
//        cout << o2 << endl;
        o2 = p-o2;

//        cout << i << '\t' << o1 << ' ' << o2 << endl;
        if(o1 <= o2) total += o2-o1+1;
    }
    out << total << endl;
}
