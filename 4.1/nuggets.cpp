/*
ID: billyz43
PROG: nuggets
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
std::ifstream in("nuggets.in");
std::ofstream out("nuggets.out");

int N; 
int nums[10];
bool dp[256];

int gcd(int a,int b){
    while(b > 0){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int ans = 0;
    in >> N;
    for(int i = 0; i < N; i++){
        in >> nums[i];
    }
    
    int g = nums[0];
    for(int i = 1; i < N; i++){
        g = gcd(g,nums[i]);
    }
    if(g > 1){
        out << 0 << endl;
        return 0;
    }

    dp[0] = true;
    for(int i = 1; i < 2000000000;i+=256){
        int cnt = 0;
  //      cout << "iii " << i << endl;
        for(int j = i; j < i+256; j++){
            int k;
            for(k = 0; k < N; k++){
                if((j >= nums[k]) && dp[(j-nums[k])&0xFF]){
                    dp[j&0xFF] = true;
                    cnt++;
                    break;
                }
            }
            if(k == N){ 
                dp[j&0xFF] = false;
                ans = j;
//                cout << j << endl;
            }
        }    
        if(cnt == 256) break;
    }
    out << ans << endl;
}
