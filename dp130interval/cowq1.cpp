/*
ID: billy
PROG: cowq
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <cmath>
#define INF 9999
std::ifstream in("cowq.in");
std::ofstream out("cowq.out");
using namespace std;
vector<int> v;
int N,B,J;
vector<int> fin;

int f[101],l[101];
int ans;

void print1(){
    for(int i = 0; i <= N; i++){
        cout << f[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i <= N; i++){
        cout << l[i] << ' ';
    }
    cout << endl;
    cout << "ans " << ans << endl;
}

void print(){
    for(auto& i : fin) cout << i << ' ';
    for(int i = v.size()-1; i >= 0; i--) cout << v[i] << ' ';
    cout << endl;
}

void dfs(int d){
    if(d == N){
        ans++;
        if(fin.size() > 0){
            f[fin[0]]++;
        } else{
            f[v.back()]++;
        }
        l[v[0]]++;
//        print();
        return;
    }
    if(!v.empty()){
        int tp = v.back();
        v.pop_back();
        fin.push_back(tp);
        dfs(d);
        fin.pop_back();
        v.push_back(tp);
    }
    v.push_back(d+1);
    dfs(d+1);
    v.pop_back();
}

int main(){
    in >> N >> B >> J;
    cout << "N " << N << endl;
    dfs(0);
    print1();
}
