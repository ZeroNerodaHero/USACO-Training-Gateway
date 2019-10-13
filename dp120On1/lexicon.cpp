/*
ID: billyz43
PROG: lexicon
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <cmath>
#define INF 160000
std::ifstream in("lexicon.in");
std::ofstream out("lexicon.out");
using namespace std;
int W, L;
string msg;
//unordered_set<string> dict;
string dict[1005];

int sl(){
    int dp[1602];
    dp[0] = 0; 
    for(int i = 1; i <= L; i++){
        dp[i] = dp[i-1]+1;

        for(int j = 0; j < W; j++){
            int c = 0,q=dict[j].size()-1,p=i-1;
            if(msg[p] != dict[j][q]){
                int k = p-1;
                while(k >= 0 && msg[k] != dict[j][q] && msg[k] != msg[p]){
                    k--;
                    c++;   
                }
                if(k >= 0) dp[i] = min(dp[i],dp[k+1] + c + 1);
            } else{
                for(; q >= 0 && p >= 0; p--){
                    if(msg[p] == dict[j][q]){
                        q--;
                    } else{
                        c++;
                    }
                }  
                if(q >= 0) continue;
                dp[i] = min(dp[i],dp[p+1] + c);
            }
        }
    }
    return dp[L];      
}

int main(){
    in >> W >> L >> msg;
    for(int i = 0; i < W; i++){
        in >> dict[i];
//        cout << dict[i] << endl;;
    }
    string s = "";
    int sm = sl();
    out << sm << endl;
//    cout << sm << endl;
}
