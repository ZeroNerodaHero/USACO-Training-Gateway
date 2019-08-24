/*
ID: billy
PROG: cownum
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("cownum.in");
std::ofstream out("cownum.out");
using namespace std;
int N,M;
int num[1001];
int dp[1001][1001];
unordered_map<int,int> m(100000);

void print(){
    for(int i = 0; i < N; i++){
        cout << num[i];
    } 
    cout << endl;
}

int dfs(int d,int n1, int n2, int n3){
    if(d == -1){
//        print();
        return 1;
    }
    int ans = 0;
    int mx = min(n2,n3);
    int st = d << 20 | n1 << 10 | mx;
    if(m.find(st) != m.end()){
        return m[st];
    }

    int i = d/2;
    if(i <= 0) i = 1;
//i=1;
    for(; i < mx; i++){
        ans += dfs(d-1,i,n1,n2);
    }
    if(ans > M) ans %= M;
    m[st]=ans;
//    cout << d << ": " << n1 << ": " << min(n2,n3) << ": " << ans  << ": " << n2 << ": " << n3 <<endl;
    return ans;
}

int main(){
    in >> N >> M;
    int ans = 0;
    for(int i = N/2; i <= N; i++){
        for(int j = N/2; j <= N; j++){
            ans += dfs(N-3,i,j,INF);
        }
    }

    ans %= M;
    out << ans << endl;
}
