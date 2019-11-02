/*
ID: billyz43
PROG: sorting
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
#define INF 999999
std::ifstream in("sorting.in");
std::ofstream out("sorting.out");
using namespace std;
int N;
int ar[1005];


void print(){
    for(int i = 1; i <= N; i++){
        cout << ar[i] << ' ';
    } 
    cout << endl;
}

void move(int x, int y){
    int tmp = ar[x];
    if(x < y){
        for(int i = x; i < y; i++){
            ar[i] = ar[i+1];
        }
    } else{
        for(int i = x; i > y; i--){
            ar[i] = ar[i-1];
        }
    }
    ar[y] = tmp;
}

int depth=0;
int dfs(){
    int ret = INF;

    cout << depth++ << ": ";
    print();

    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            if(ar[i] < ar[j]){
                move(i,j);
                ret = min(ret,i+j+dfs());
                move(j,i);
            }
        }
    }

    for(int i = N; i > 1; i--){
        for(int j = i-1; j >= 1; j--){
            if(ar[i] > ar[j]){
                move(i,j);
                ret = min(ret,i+j+dfs());
                move(j,i);
            }
        }
    }

    if(ret == INF) ret = 0, cout << "returning \n";
    depth--;
    return ret;
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        in >> ar[i];
    }

    int ret = dfs();
    cout << ret << endl;
}
