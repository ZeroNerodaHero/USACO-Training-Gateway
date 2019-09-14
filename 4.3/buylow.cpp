/*
ID: billyz43
PROG: buylow
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cstring>
using namespace std;
std::ifstream in("buylow.in");
std::ofstream out("buylow.out");

struct bignum{

};

int N;
int ar[5000];
int dp[5000];
int dc[5000];
bool skip[5000];

void print(){
    for(int i = 0; i < N; i++){
        cout << std::setw(2);
        cout << ar[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << std::setw(2);
        cout << dp[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << std::setw(2);
        cout << dc[i] << ' ';
    }
    cout << endl;
    cout << endl;
}

int main(){
    in >> N;

    for(int i = 0; i < N; i++){
        in >> ar[i];
        dp[i] = 1;
        dc[i] = 1;
    } 

    for(int i = 1; i < N; i++){
        for(int j = i-1; j >= 0; j--){
            if(skip[j]) continue;
            if(ar[i] < ar[j]){
                if(dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    dc[i] = dc[j];
                } else if(dp[j]+1 == dp[i]){
                      dc[i] += dc[j];
                }
            } else if(ar[i] == ar[j]){
                if(dp[i] == 1 || dp[i] < dp[j]){
                    skip[i] = true;
                    break;
                } else if(dp[i] == dp[j]){
                    break;
                }
            } 
        }
    }
//    print();
    int longest = 0;
    int longseq = 0;
    for(int i = 0; i < N; i++){
//        cout << longest << ' ' << longseq << endl;
        if(dp[i] > longest){
            longest = dp[i];
            longseq = dc[i];
        } else if(dp[i] == longest){
            longseq += dc[i];
        }
    }
    out << longest << ' ' << longseq << endl;
}
