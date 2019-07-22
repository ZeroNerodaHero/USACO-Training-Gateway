/*
ID: billy
PROG: fence8
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
std::ifstream in("fence8.in");
std::ofstream out("fence8.out");
using namespace std;
int N,R;
int a[50];
int b[50];
int ar[1024];
int c[1024];
int M;

bool dfs(int n){
    if(n == -1) return true;

    int i = 0;    
    
    if(n < M && ar[n] == ar[n+1]){
        i = c[n+1];
    }
    for(; i < N; i++){
        if(ar[n] > b[i]) continue;
        b[i] -= ar[n];
        c[n] = i; 
        if(dfs(n-1)){
            return true;
        }
        b[i] += ar[n];
    } 
    return false;
}

bool best(int mid){
    for(int i = 0; i < N; i++){
        b[i] = a[i];
    }
    M = mid-1;
    return dfs(mid-1);   
}

int main(){
    int t = 0, tar =0;
    in >> N;
    for(int i = 0; i < N; i++){
        in >> a[i];
        t += a[i];
    }
//    cout << "t\t" << t << endl;
    in >> R; 
    for(int i = 0; i < R; i++){
        in >> ar[i];
    }
    sort(ar,ar+R);
    int i = 0;
    for(; i < R; i++){
        tar += ar[i];
        if(tar > t) break;
    }
//    cout << R << '-' << i << endl;
    R = i;
    int l = 0, r= R;
    while(l < r){
        int mid = (l+r+1)/2;
        cout << l << '-' << r << '-' <<  mid << endl;

        if(best(mid)) l = mid;
        else r = mid-1;
    }
    out << l << endl;
}

