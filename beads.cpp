/*
ID: NomNom isHere
PROG: beads
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("gift1.in");
    std::ofstream out("gift1.out");
    
    int size, necksize = 0;
    in >> size;
    int count[size];
    char last;
    in >> last;
    count[necksize] = 1;
    for(int i = 0; i < size-1; i++){
        char bead;
        in >> bead;
        if(in == last) count[necksize]++;
    }
}
