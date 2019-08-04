/*
ID: billy
PROG: clocks
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <map>
#include <math.h>
using namespace std;
std::ifstream in("clocks.in");
std::ofstream out("clocks.out");

struct node{
    int p, o;
    node(int p, int o):p(p),o(o) {}
    node() {}
};
int cur;
int mask = 0;
int times = 1;
string op1[10] = {"","ABDE","ABC","BCEF","ADG","BDEFH","CFI","DEGH","GHI","EFHI"};
int op[10];
unordered_map<int,node> m(600000);
vector<int> ans;

void bfs(int s){
    queue<int> q;
    q.push(s);
    m[s] = node(0,0);
    
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
//        cout << dec << times++ << '\t' << oct << tmp << endl;
        for(int i = 1; i < 10; i++){
            int n = tmp + op[i];
            n &= mask;
            if(n == 0){
                ans.push_back(i);
                int p = tmp;
                while(p != s){
                    ans.push_back(m[p].o);
                    p = m[p].p;
                }
                return;
            }
            if(m.find(n) == m.end()){
                m[n] = node(tmp,i);
                q.push(n);
            }
        }
    }
}

void print(){
    cout.width(9);
    cout.fill('0');
    for(int i = 1; i < 10; i++){
        cout << oct <<op[i] << endl;
    }
    cout << "mask " << mask << endl;
    cout << "cur " << cur << endl;
}

int main(){
    for(int i = 0; i < 9; i++){
        int tmp;
        in >> tmp;
        tmp /= 3;
        cur |= (tmp<<(3 * i));
        mask <<= 3;
        mask |= 3;
    }
    cur &= mask;
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < op1[i].size(); j++){
            op[i] |= 1<<(3 * (op1[i][j]-'A'));
        }
    }
//    print();
    bfs(cur);

    for(int i = ans.size()-1; i >= 0; i--){
        if(i != ans.size()-1){
            out  << ' ';
        }
        out << ans[i];
    }
    out << endl;
}
