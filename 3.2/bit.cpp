/*
ID: billy
PROG: kimbits
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("kimbits.in");
std::ofstream out("kimbits.out");

unsigned int N,L,I;
unsigned int dp[32][32];
int sums[32];

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= L; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    in >> N >> L >> I;

    for(int i = 0; i < N; i++){
        dp[i][0] = 1;
    }
    for(int j = 1; j <= L; j++){
        dp[0][j] = 2;
    }
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= L; j++){
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }    

//    print();
    
    if(I > dp[N-1][L]){
        out << "impossible\n";
        return 0;
    }
    I--;

    for(int i = N-2; i >= 0; i--){
  //      cout << I << ' ' << dp[i][L] << endl;
        if(I >= dp[i][L]){
            out << '1';
            I -= dp[i][L];
            L--;
        } else{
            out << '0';
        }
    }
    out << I;
    out << endl;
}
