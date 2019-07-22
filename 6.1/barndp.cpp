/*
ID: billy
PROG: rectbarn
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <list>
#define MAXN 100005
using namespace std;
std::ifstream in("rectbarn.in");
std::ofstream out("rectbarn.out");

int R,C,P;
bool g[3001][3001];
int ch[3002];;
int l[3002],r[3002];
int marea = 0;

void print(){
    for(int i = 1; i <= C; i++) cout << ch[i] << ' '; cout << endl;
    for(int i = 1; i <= C; i++) cout << l[i] << ' '; cout << endl;
    for(int i = 1; i <= C; i++) cout << r[i] << ' '; cout << endl;
}

int main(){
    in >> R>>C>>P;
    for(int i = 0; i < P; i++){
        int a, b;   
        in >> a >> b;
        g[a][b] = 1;        
    }
    for(int i = 1; i <= R; i++){
        int w = 0;
        for(int j = 1; j <= C; j++){
            if(g[i][j]){
                ch[j] = 0;
                l[j] = r[j] = 0;
                w = 0;
            }
            else{
                ch[j]++;
                w++;
                if(ch[j] == 1){
                    l[j] = w;
                } else{
                    l[j] = min(l[j],w);
                }
                
            }
        }
        w = 0;
        for(int j = C; j >= 1; j--){
            if(g[i][j]){
                w = 0;
            } else{ 
                w++;
                if(ch[j] == 1){
                    r[j] = w;
                } else{
                    r[j] = min(r[j],w);
                }
            }
        }
    //    print();
        for(int j = 1; j <= C; j++){
            int area = ch[j] * (l[j] + r[j] - 1);
//            cout << area << ' ';

            marea = max(marea,area);
        }
  //      cout << endl;
    //    cout << endl;
    }
    out << marea << endl;
}
