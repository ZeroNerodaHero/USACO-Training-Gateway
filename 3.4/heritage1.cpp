/*
ID: billyz43
PROG: heritage
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
std::ifstream in("heritage.in");
std::ofstream out("heritage.out");

void build(string tin, string tpre){
//    cout << tin << '\t' << tpre << endl;
    if(tin.size() == 1){
        out << tin[0];
        return;
    }
    if(tin.size() == 0) return;
    int mid = tin.find(tpre[0]);
    build(tin.substr(0,mid),tpre.substr(1,mid));
    build(tin.substr(mid+1),tpre.substr(mid+1));
    out << tpre[0];
}

int main(){
    string tin, tpre;
    in >> tin >> tpre;
    build(tin,tpre);   
    out << endl;
}
