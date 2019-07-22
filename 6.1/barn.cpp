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
int marea = 0;

void rect(){
    stack<int> s;
    s.push(0);
        
    for(int i = 1; i <= C+1; i++){
        int tmp = s.top();
        if(ch[tmp] <= ch[i]) s.push(i);
        else{
            do{
                tmp = s.top();
                s.pop();
                int area = ch[tmp] * (i-s.top()-1);
                marea = max(marea,area);
            } while(ch[s.top()] > ch[i]);
            s.push(i);
        } 
    }
}

int main(){
    in >> R>>C>>P;
    for(int i = 0; i < P; i++){
        int a, b;   
        in >> a >> b;
        g[a][b] = 1;        
    }
    for(int i = 1; i <= R; i++){
        bool skip = true;
        for(int j = 1; j <= C; j++){
            if(g[i][j]){
                ch[j] = 0;
                skip = false;
            }
            else ch[j]++;
        }
        if(!skip || i == R) rect();    
    }
    out << marea << endl;
}
