/*
ID: billyz43
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
unsigned int dp[40][1000];

int N, total = 0;
int sub(int i, int sum){
    if(sum == total) return 1;
    if(i > N || sum > total){
        return 0;
    } 
    return sub(i+1,sum+i) + sub(i+1,sum);
}

int sub1(int i, int sum){
    if(sum == 0) return 1;
    if(sum < 0 || i <= 0){
        return 0;
    }
    return sub1(i-1,sum-i) + sub1(i-1,sum);
}

unsigned int sub(){
    for(int i = 0; i <= N; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= total; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= i) dp[i][j] += dp[i-1][j-i];
        }
    }
    return dp[N][total]/2;
}
int main(){
    std::ifstream in("subset.in");
    std::ofstream out("subset.out");
    in >> N;
    int count = 0;
    for(int i = 1; i <= N; i++){
        total += i;
    }
    if(total&1) out << '0' << endl;
    else{
        total = total/2;
        out << sub() << endl;
    }
}
