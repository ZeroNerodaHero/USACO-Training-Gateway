/*
ID: billyz43
PROG: combo
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("combo.in");
    std::ofstream out("combo.out");

    int N;
    in >> N;
    int a[3],b[3];
    for(int i = 0; i < 3; i++){
        in >> a[i];
    }
    for(int i = 0; i < 3; i++){
        in >> b[i];
    }
    if(N <= 5){
        out << N * N * N << endl;
        return 0;
    } 
    int over = 1;
    for(int i = 0; i < 3; i++){
        int c = abs(a[i]-b[i]);
        if(c > 4){
            c = N-c;   
        }
        if(c > 4){
            over = 0;
            break;
        }
        over *= 5-c;
    }
    out << 250 - over << endl;
    return 0;   
}
