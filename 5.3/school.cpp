/*
ID: billyz43
PROG: schlnet
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
std::ifstream in("schlnet.in");
std::ofstream out("schlnet.out");

int N, c,com;
list<int> g[101];
int ind[101],outd[101];
int low[101];
int disc[101];
int instack[101];
int tin,tout;
stack<int> s;


void print(){
    for(int i = 1; i <= N; i++){
        cout << "g" << i << ' ';
        for(auto &j: g[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
        cout << endl;
}

void print1(){
    for(int i = 1; i <= N; i++){
        cout << low[i] << ' ';
    }
    cout << endl;
    for(int i = 1; i <= N; i++){
        cout << disc[i] << ' ';
    }
    cout << endl;
    
}

void dfs(int u){
    disc[u] = low[u] = ++c;
    s.push(u);
    instack[u] = true;
    for(auto &i: g[u]){
        if(disc[i] == 0){
            dfs(i);
            low[u] = min(low[u],low[i]);
        } else{
            if(instack[i]){
                low[u] = min(low[u],low[i]);
            }
        }
    }
    //cout << u << " disc " << disc[u] << " low " << low[u] << endl;
    if(low[u] == disc[u]){
        com++;
        //cout << u << " low " << low[u] << endl;;
        int v;
        do{
            v = s.top();
            s.pop();
            instack[v] = false;
            low[v] = low[u];
            //cout << v << ' ';
        } while(v != u);
        //cout << endl;
    }
}

void tarjan(){
    for(int i = 1; i <= N; i++){
        if(disc[i] == 0){
            dfs(i);
        }
    }
//    print1();
}

void getdir(){
    for(int i = 1; i <= N; i++){
        for(auto &j: g[i]){
            if(low[i] != low[j]){
                outd[low[i]]++;
                ind[low[j]]++;
            }    
        }
    }

    for(int i = 1; i <= N; i++){
        if(disc[i] == low[i]){
            if(outd[low[i]] == 0) tout++;
            if(ind[low[i]] == 0) tin++;
        }
    }
}

int main(){
    in >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 0;;j++){
            int k;      
            in >> k;
            if(k == 0) break;
            g[i].push_back(k);
        }
    }

    //print();
    tarjan();
    getdir();
    
    out << tin << endl;
    if(com == 1) out << 0 << endl;
    else out << max(tin,tout) << endl;
}
