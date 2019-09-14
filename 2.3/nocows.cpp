/*
ID: billyz43
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int N,K;
int count = 0;
int dp[200][105];
int cow(int N, int K){
    for(int i = 0; i < K; i++){
        dp[0][i] = 1;
        dp[1][i] = 1;
    }
    for(int i = 1; i < K; i++){
        for(int j = 2; j < N; j++){
            for(int l = 0; l <= j-2; l+=2){
                dp[j][i] = dp[l][i-1] * dp[j-l-1][i-1];
                dp[j][i] %= 9901; 
            }
        }
    }
    return dp[N][K];
}

int cow1(int n, int k){
    if(dp[n][k] >= 0) return dp[n][k];

    if(k == 0){
        dp[n][k] = 0;
        return dp[n][k];;
    }
    if(n == 1){ 
        dp[n][k] = 1;
        return dp[n][k];;
    }

    int total = 0;
    for(int i = 1; i < n; i+=2){
        total += cow1(i,k-1) * cow1(n-i-1,k-1);
        total %= 9901;
    }
    dp[n][k] = total;
    return dp[n][k];;
}

int cowdp(){
    for(int i = 1; i <= K; i++){
        dp[1][i] = 1;
    }
    for(int n = 3; n <= N; n+= 2){
        for(int k = 1; k <= K; k++){
            int total = 0;
            for(int i = 1; i < n; i+=2){
                total += cow1(i,k-1) * cow1(n-i-1,k-1);
                total %= 9901;
            }
            dp[n][k] = total;
        }
    }
    return dp[N][K];
}
int cow1t(int n, int k){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= K; j++){
            dp[i][j] = -1;
        }
    }
    return cow1(n,k);
}
int cow2(int n, int k){
    if(k == 0) return 0;
    if(n == 1) return 1;

    int total = 0;
    for(int i = 1; i < n; i+=2){
        total += cow2(i,k-1) * cow2(n-i-1,k-1);
    }
    return total;
}

void print(){
    for(int i = 0; i <= N; i++){
        for(int k = 0; k <= K; k++){
            std::cout << dp[i][k] << ' ';
        }
        std::cout << endl;
    }
}

int main(){
    std::ifstream in("nocows.in");
    std::ofstream out("nocows.out");
    in >> N >> K;
    cowdp();
    print();
    out << (dp[N][K]-dp[N][K-1]+9901)%9901 << endl;;
    //out << (cow1t(N,K)-cow1t(N,K-1)+9901)%9901 << endl;
}
