/*
ID: billyz43
PROG: elevator
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#define INF 9999
std::ifstream in("elevator.in");
std::ofstream out("elevator.out");
using namespace std;
int K;
int h[401],a[401];
int c[401];

int dfs(int y){
    int res = y;
    for(int i = 0; i < K; i++){
        if(c[i] > 0 && y+h[i] <= a[i]){
            c[i]--;
            res = max(res,dfs(y+h[i]));
            c[i]++;
        }
    }
    return res;
}

int main(){
    in >> K;
    for(int i = 0; i < K; i++){
        in >> h[i] >> a[i] >> c[i];
    }
    int res = dfs(0);
    cout << res << endl;
}
