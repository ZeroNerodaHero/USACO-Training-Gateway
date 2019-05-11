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
int N,mask;
vector<int> v;
int dx[4] = {-2,-1,1,2};

bool dfs(int s,int l){
    //cout << "at " <<  l << ' ' << hex << s << endl;
    if(l == N){
        if((s & mask) == 0){
            return true;
        }
    }

    for(int i = 0; i < 4; i++){
        int m = l+dx[i];
        if(m >= 0 && m <= 2*N){
        //cout << m << endl;
            if(dx[i] < 0){
                //move w
                if((s & (1<<m)) > 0){
                    int n = (s & (~(1<<m)));
                    n |= (1<<l);
                    v.push_back(m);
                    if(dfs(n,m)) return true;
                    v.pop_back();
                }
            } else{
                if((s & (1<<m)) == 0){
                    //int n = (s | (1<<m));
                    v.push_back(m);
                    if(dfs(s,m)) return true;
                    v.pop_back();
                }
            }
        }
    }
    return false;
}

int main(){
    in >> N;
    
    mask = (1<<N)-1;
    dfs(mask,N);  
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
