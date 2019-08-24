/*
ID: billy
PROG: trt
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
#include <climits>
#define INF 9999
std::ifstream in("trt.in");
std::ofstream out("trt.out");
using namespace std;

int N;
int trt[2001];

int dfs(int i, int j, int a){
    if(i == j) return trt[i] * a;
    int ans = dfs(i+1,j,a+1) + trt[i] * a;
    ans = max(ans,dfs(i,j-1,a+1) + trt[j] * a);
    return ans;
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >>trt[i];
    }
    int ans = dfs(0,N-1,1);
    cout << ans << endl;
}
