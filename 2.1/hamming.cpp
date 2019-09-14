/*
ID: billyz43
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int N,B,D;

void print(int dp[], int size){
    for(int i = 0; i < size; i++){
        std::cout << dp[i] << '\n';
    } std::cout << endl;
}

namespace ns1{
int countbit(int i){
    int count = 0;
    while(i != 0){
        if((i&1)==1) count++;
        i=i>>1;
    } 
    return count;
}
}

namespace ns2{
int countbit(int i){
    int count = 0;
    while(i != 0){
        count++;
        i = i & (i-1);
    }
    return count;
}
}


namespace ns3{
int dp[256];
void gen(int n){
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i>>1] + (i&1);
    }
    print(dp,256);
}

inline int countbit(int i){
    return dp[i];
}
}
namespace my = ns3;
using namespace my;
bool isokay(int ar[],int size,int num){
    for(int i = 0; i < size; i++){
        if(my::countbit(ar[i]^num) < D) return false;
    }
    return true;
}

int main(){
    gen(256);
    std::ifstream in("hamming.in");
    std::ofstream out("hamming.out");

    in >> N >> B >> D;
    int limit = 1<<B, size = 0, prev = 0;
    int ar[N];
    ar[size++] = 0;
    
    for(int i = 1; size < N && i < limit; i++){
        if(isokay(ar,size,i)){
        std::cout << prev << "\t" << i << "\t" << (prev^i) << "\t" << countbit(prev^i) << endl;
            ar[size++] = i;
        }          
    }

    out << ar[0] << ' ';
    for(int i = 1; i < size-1; i++){
        if(i%10==9){ out << ar[i] << endl;}
        else out << ar[i] << ' ';
    }
    out << ar[size-1] << endl;

    return 0;
}

