/*
ID: billy
PROG: shuttle
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
std::ifstream in("shuttle.in");
std::ofstream out("shuttle.out");
int N;
char ar[25];
vector<int> v;
int dx[4] = {-2,-1,1,2};

bool check(){
    for(int i = 0; i < N; i++){
        if(ar[i] == 'W') return false;
    }
    return true;
}

bool dfs(int l){
    if(l == N){
        if(check()) return true;
    }

    for(int i = 0; i < 4; i++){
        int m = l+dx[i];
        if(m >= 0 && m <= 2*N){
        //cout << m << endl;
            if(dx[i] < 0){
                if(ar[m] == 'W'){
                    swap(ar[m],ar[l]);
                    v.push_back(m);
                    if(dfs(m)) return true;
                    swap(ar[m],ar[l]);
                    v.pop_back();
                }
            } else{
                if(ar[m] == 'B'){
                    swap(ar[m],ar[l]);
                    v.push_back(m);
                    if(dfs(m)) return true;
                    swap(ar[m],ar[l]);
                    v.pop_back();
                }
            }
        }
    }
    return false;
}

int main(){
    in >> N;
    
    for(int i = 0; i < N; i++){
        ar[i] = 'W';    
    }
    ar[N] = ' ';
    for(int i = N+1; i <= 2*N; i++){
        ar[i] = 'B';    
    }

    dfs(N);  
    int c = 0;
    for(int i = 0; i < v.size(); i++){
        if(c == 19 || i == v.size()-1){
            out << v[i]+1 << endl;
            c = 0;
        } else{
            c++;       
            out << v[i]+1 <<  ' ';
        }
    }
}
