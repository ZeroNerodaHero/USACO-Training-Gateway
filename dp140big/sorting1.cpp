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
int best = INF;

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
void dfs(int cur){
    if(cur >= best) return;
    bool sorted = true;

    //cout << depth++ << ": "; print(); 
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            if(ar[i] < ar[j]){
                sorted = false;
                move(i,j);
                dfs(i+j+cur);
                move(j,i);
            }
        }
    }

    for(int i = N; i > 1; i--){
        for(int j = i-1; j >= 1; j--){
            if(ar[i] > ar[j]){
                sorted = false;
                move(i,j);
                dfs(i+j+cur);
                move(j,i);
            }
        }
    }

    
    if(sorted) best = cur; 
    depth--;
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        in >> ar[i];
    }
    dfs(0);
    out << best << endl;
}
