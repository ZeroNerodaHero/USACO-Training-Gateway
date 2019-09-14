/*
ID: billyz43
PROG: calfflac
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("calfflac.in");
std::ofstream out("calfflac.out");
string s = "",tmp;
int dp[4][20005];
int longest = 1;
int al, ar;
int t;
int ind[20000];

void lower(){
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] -'A' + 'a';
        }
        if(s[i] >= 'a' && s[i] <= 'z'){
            ind[t] = i;
            s[t] = s[i];
            t++;
        }
    }
}

void pal(){
    for(int i = 0; i < t; i++){
        dp[0][i] = 1;
        if(s[i] == s[i+1]){
            dp[1][i] = 2;
            if(dp[1][i] > longest){
                longest = dp[1][i];
                al = i;
            }
        } else{
            dp[1][i] = 0;
        } 
    }
 
    for(int l = 2; l < 2000; l++){
        int b = l&3,a=(l-2)&3;
        for(int i = 0; i+l < t; i++){
            if(s[i] == s[i+l]){
//                cout << i << ' ' << dp[a][i+1] << endl; 
                if(dp[a][i+1] > 0){
                    dp[b][i] = dp[a][i+1]+2;
                    if(dp[b][i] > longest){
                        longest = dp[b][i];
                        al = i;
//                        cout << longest << endl;
                    }
                } else{
                    dp[b][i] = 0;
                }
            } else{
                dp[b][i] = 0;
            }
        }
    }   
}


void print(){
    int s = ind[al], l= ind[ar] - ind[al] +1;
    while(l> 0){
        if(l < 79){
            out << tmp.substr(s,l) << endl;
            l = 0;
        } else{
            out << tmp.substr(s,79) << endl;;
            s += 79;
            l -= 79;
        }
    }
}

int main(){
    while(getline(in,tmp)){
        s+= tmp + '\n';
    } 
    tmp = s;
    lower();
    pal();
    out << longest << endl;
    ar = longest-1 + al;
    //print();
    out << tmp.substr(ind[al],ind[ar]-ind[al]+1) << endl;;
}
