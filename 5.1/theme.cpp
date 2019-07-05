/*
ID: billy
PROG: theme
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <utility>
using namespace std;
std::ifstream in("theme.in");
std::ofstream out("theme.out");
int N;
int dp[2][5000];
int note[5001];

void find(){
    int big = 0;
    //memset(dp,0,sizeof(dp));

    for(int i = 1; i < N; i++){
        for(int j = 1; j < N; j++){
            dp[i&1][j] = 0;
        }
        for(int j = i+1; j < N; j++){
            if(note[i] == note[j] && (j-i) > dp[(i-1)&1][j-1]+1){
                dp[i&1][j] = dp[(i-1)&1][j-1] + 1;
/*                if(big < dp[i&1][j]){
                    cout << i << "-" << note[i] << ' ' << j << '-' << note[j]<< ' ' << big << endl;
                }
*/
                big = max(dp[i&1][j],big);
            }
        }
    }
    if(big >= 4){
        out << big+1 << endl;
    } else{
        out << 0 << endl;
    }
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> note[i];
    }

    for(int i = N-1; i > 0; i--){
        note[i] -= note[i-1];
    }    
/*
    cout << note[58] << endl;;
    for(int i = 1; i < N; i++){
        cout << note[i] << ' ';
    }
    cout << endl;
*/
     find();
}
