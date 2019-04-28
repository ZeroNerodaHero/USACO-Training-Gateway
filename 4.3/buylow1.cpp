/*
ID: billy
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
#define MAXN 200
using namespace std;
std::ifstream in("buylow.in");
std::ofstream out("buylow.out");

struct bignum{
    int w;
    int d[MAXN];
    bignum(){
        clear();
    }
    void clear(){
        w = 0;
        for(int i = 0; i < MAXN; i++){
            d[i] = 0;
        }
    }
};

void operator+= (bignum& l, const bignum& r){
    int maxw = max(l.w,r.w);
    int carry = 0;
    int sum = 0;

    for(int i = 0; i <= maxw; i++){
        sum = carry + l.d[i] + r.d[i];
        carry = sum/10;
        l.d[i] = sum%10;
    }
    l.w = maxw;
    if(carry > 0){
        l.w++;
        l.d[l.w] = carry; 
    }
}

ostream& operator <<(ostream& os, bignum& b){
    for(int i = b.w; i >= 0; i--){
        os << b.d[i];
    }
    return os;
}

int N;
int ar[5000];
int dp[5000];
bignum dc[5000];
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

void print1(int longest){
    for(int i = 0; i < N; i++){
        if(dp[i] == longest){
            cout << dc[i] << endl;
        }
    }
}

int main(){
    in >> N;
#if 0
    bignum a, b;
    a.d[0] = 4;
    b.d[0] = 5;
    b.d[1] = 1;
    b.w = 1;
    b+=a;
    cout << "a\t" << b <<endl;
    return 0;
#endif
    for(int i = 0; i < N; i++){
        in >> ar[i];
        dp[i] = 1;
        dc[i].d[0] = 1;
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
                    dc[i].clear();
                    skip[i] = true;
                }
                break;
            } 
        }
    }
//    print();
    int longest = 0;
    bignum longseq;
    for(int i = 0; i < N; i++){
  //      cout << longest << ' ' << longseq << endl;
        if(dp[i] > longest){
            longest = dp[i];
            longseq = dc[i];
        } else if(dp[i] == longest){
            longseq += dc[i];
        }
    }
//    print1(longest);
    out << longest << ' ' << longseq << endl;
}
