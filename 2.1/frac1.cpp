/*
ID: billyz43
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int N;
struct frac{
    int num,den;
    frac(int num, int den): num(num),den(den) {}
    frac() {}
    bool operator<(const frac& o) const{
        if((num * o.den) == (o.num * den)){
            return den < o.den;
        }
        return (num * o.den) < (o.num * den);
    }
    bool operator==(const frac& o) const{
        return (num * o.den) == (o.num * den);
    }
};
frac all[25600];

int main(){
    std::ifstream in("frac1.in");
    std::ofstream out("frac1.out");
    in >> N;
    int size = 0;
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            std::cout << "works@" << i << ' ' << j<< endl;
            all[size++] = frac(i,j);
        }
    }    
    std::sort(all,all+size);
    //for(int i = 0; i < size; i++){
      //  cout << all[i].num << '/'<< all[i].den << endl;
    //}
    out << "0/1\n";
    for(int i = 0; i < size; i++){
        if(i != 0 && all[i-1] == all[i]) continue;
        out << all[i].num << '/'<< all[i].den << endl;
        if(all[i] == frac(1,1)) return 0;
    }
}

//add all the numbers in 
//sort
//eliminate

