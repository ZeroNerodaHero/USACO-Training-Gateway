/*
ID: billyz43
PROG: treasures
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
#define INF 160000
std::ifstream in("treasures.in");
std::ofstream out("treasures.out");
using namespace std;
struct node{
    int x,y,p,c,sx,ex;;
    bool operator < (node const& o) const{
        if(sx == o.sx) return ex < o.ex;
        return sx < o.sx;
    }
};

int N;
node ar[1000];

int over(int i, int j){
    int b = (ar[i].ex - ar[j].sx);
    if(b&1){
        b /= 2;
        return b*b+b;
    } else{
        b /= 2;
        return b*b;
    }
}
void printar(){
    for(int i = 0; i < N; i++){
        cout << ar[i].x << ',' << ar[i].y << "\t";
    } cout << endl;
}

bool v[1000];
int p[100];

void print(){
    for(int i = 0; i < N; i++){
        cout << v[i] << ' ';
    } cout << endl;
    for(int i = 0; i < N; i++){
        cout << p[i] << ' ';
    } cout << endl;
    cout << endl;
}
int dfs(int c){
    if(c == N){
        print();
        return 0;
    }
    int ans = dfs(c+1);
    int sum = 0;
    for(int i = 0; i < c; i++){
        if(v[i] && ar[c].sx < ar[i].ex){
            if(ar[c].ex <= ar[i].ex){
                sum = ar[c].c;
                break;
            } else{
                sum = max(sum,over(i,c));
            }
        }
    }
    v[c] = true;
    p[c] = ar[c].p-ar[c].c+sum;
    int tmp = ar[c].p-ar[c].c+sum+dfs(c+1);
    ans = max(ans,tmp);
    v[c] = false; 
    p[c] = 0;
    return ans;
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        in >> ar[i].x >> ar[i].y >> ar[i].p;
        ar[i].sx = ar[i].x+ar[i].y;
        ar[i].ex = ar[i].x-ar[i].y;
        ar[i].c = (ar[i].y* ar[i].y);
    }
    sort(ar,ar+N);
//    printar();
    int ans = dfs(0);
    out << ans << endl;
}
