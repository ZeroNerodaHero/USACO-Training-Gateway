/*
ID: billyz43
PROG: humble
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("humble.in");
std::ofstream out("humble.out");

int val[10000];
int cur[10000];

int main(){
    int K, N;
    in >> K >> N;
    int multi[K];
    for(int i = 0; i < K; i++){
        in >> val[i];
        multi[i] = val[i];
    }
    int dp[N];
    dp[0] = 1;
    for(int i = 1; i <= N; i++){
        int small = multi[0];;
        for(int j = 1; j < K; j++){
            small = min(small,multi[j]);
        }  
        dp[i] = small;
        for(int k = 0; k < K; k++){
            if(multi[k] == small){
                cur[k]++;
                multi[k] = dp[cur[k]] * val[k];
            }
        }
//        cout << small << ' ';
    }
    //cout << endl;
    out << dp[N] << endl;
}

