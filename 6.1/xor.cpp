/*
ID: billy
PROG: cowxor
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("cowxor.in");
std::ofstream out("cowxor.out");
int N, big = 0, ana = 0, anb = 1;
int pre[MAXN];

struct node{
    node * h0,* h1;
    int ind;
    node(){ h0 = h1 = nullptr;ind = MAXN;}
};
node top;

void insert(int a){
    node *tmp = &top;
    for(int i = 20; i >= 0; i--){
        if(((pre[a]>>i)&1) == 1){
            if(tmp->h1 == nullptr){
                tmp->h1 = new node();
            }
            tmp = tmp->h1;
        } else{
            if(tmp->h0 == nullptr){
                tmp->h0 = new node();
            }
            tmp = tmp->h0;
        }
    }
    tmp->ind = min(tmp->ind,a);;
}

void find(int a){
    node *tmp = &top;
    for(int i = 20; i >= 0; i--){
        if(((pre[a]>>i)&1) == 0){
            if(tmp->h1 == nullptr){
                tmp = tmp->h0;
            } else{
                tmp = tmp->h1;
            }
        } else{
            if(tmp->h0 == nullptr){
                tmp = tmp->h1;
            } else{
                tmp = tmp->h0;
            }
        }
    }
    if(tmp->ind <= a) return;
    int large = pre[a] ^ pre[tmp->ind];
//    cout << "tmp " << tmp->ind << ' ' << pre[tmp->ind] << " large " << large <<endl;
    if(large > big || (large == big && (((anb == tmp->ind && ana < a)) || anb > tmp->ind))){
        big = large;
        ana = a;
        anb = tmp->ind;
    }
}

int main(){
    in >> N >> pre[1];
    insert(0);
    insert(1);
        

    for(int i = 2; i <= N; i++){
        int a;
        in >> a;
        pre[i] = pre[i-1]^a;
        insert(i);
    } 
    
    for(int j = 0; j < N; j++){
        find(j);
    }
    out << big << ' ' << ana+1 << ' ' << anb << endl;
}
