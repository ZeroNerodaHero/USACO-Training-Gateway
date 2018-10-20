/*
ID: billy
PROB: pprime
LANG: C++11
*/
#include <iostream>
#include <math.h>
#include <queue>
#include <fstream>
    std::ifstream in("pprime.in");
    std::ofstream out("pprime.out");
using namespace std;
    int a,b;
int prime[3] = {5,7,11};
int odd[4] = {1,3,7,9};
int base[4] = {10,100,1000,10000};

typedef pair<int,int> bpair;
typedef void (*pf)(int);

bool isprime(int n){
    int y = sqrt(n);
    for(int i = 3; i <= y; i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}
int d1,d2,d3,d4,pa;
void level34(int l){
    for (d1 = 0; d1 < 4; d1++) {  /* only odd; evens aren't so prime */
        for (d2 = 0; d2 <= 9; d2++) {
                if(l&1){
                    pa = 100*odd[d1] + 10*d2 +odd[d1];
                }
                else{
                    pa = 1000*odd[d1] + 100*d2+10*d2+ odd[d1];
                }
                if(pa >= a && pa <= b && isprime(pa)) out<<pa << endl;
            }
        }   
}


void level56(int l){
    for (d1 = 0; d1 < 4; d1++) {  /* only odd; evens aren't so prime */
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
                if(l&1){
                    pa = 10000*odd[d1] + 1000*d2 +100*d3 + 10*d2 + odd[d1];
                }
                else{
                    pa = 100000*odd[d1] + 10000*d2 +1000*d3+100*d3+10*d2 + odd[d1];
                }
                if(pa >= a && pa <= b && isprime(pa)) out<<pa << endl;
            }
        }   
    }
}

void level78(int l){
    for (d1 = 0; d1 < 4; d1++) {  /* only odd; evens aren't so prime */
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
            for (d4 = 0; d4 <= 9; d4++) {
                if(l&1){
                    pa = 1000000*odd[d1] + 100000*d2 +10000*d3 +1000*d4+100*d3+ 10*d2 + odd[d1];
                }
                else{
                    pa = 10000000*odd[d1] + 1000000*d2 +100000*d3 +10000*d4+1000*d4+100*d3+ 10*d2 + odd[d1];
                }
                if(pa >= a && pa <= b && isprime(pa)) out<<pa << endl;
            }
            }
        }   
    }
}

int main(){
    in >> a >> b;
    std::cout << a << ' ' << b << std::endl;
    for(int i = 0; i < 3 && prime[i] <= b; i++){
        if(a > prime[i]) continue;
        out << prime[i] << endl;
    }

    pf p[3];
    p[0] = level34;
    p[1] = level56;
    p[2] = level78;
    for(int i = 0; i < 3; i++){
        p[i](0);
        p[i](1);
    }
    return 0;
}

