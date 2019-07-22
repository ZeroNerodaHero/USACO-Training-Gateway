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
int ch[2][3002],cw[2][3002];
int marea = 0;

int main(){
    in >> R>>C>>P;
    for(int i = 0; i < P; i++){
        int a, b;   
        in >> a >> b;
        g[a][b] = 1;        
    }
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(g[i][j]){
                ch[i&1][j] = 0;             
                cw[i&1][j] = 0;
            }
            else{
                int b = 0, w,h;
                ch[i&1][j] = ch[(i-1)&1][j] + 1;
                cw[i&1][j] = min(cw[(i-1)&1][j],cw[i&1][j-1]+1);
                int area = ch[i&1][j] * cw[i&1][j];
//                cout << i << ' ' << j << '\t' << area << ' ' << ch[i][j] << ' ' << cw[i][j] << endl;

                w = cw[i&1][j-1]+1;
                h = min(ch[(i-1)&1][j]+1,ch[(i)&1][j-1]);
                b = h * w;
                if(b > area){
                    area = b;
                    ch[i&1][j] = h;
                    cw[i&1][j] = w;
                }
  //              cout << i << ' ' << j << '\t' << area << ' ' << ch[i][j] << ' ' << cw[i][j] << endl;

                w = min(cw[(i)&1][j-1],cw[(i-1)&1][j-1])+1;
                h = min(ch[(i-1)&1][j],ch[(i-1)&1][j-1])+1;
                b = h*w;
                if(area > b){
                    area = b;
                    ch[i&1][j] = h;
                    cw[i&1][j] = w;
                }
    //            cout << i << ' ' << j << '\t' << area << ' ' << ch[i][j] << ' ' << cw[i][j] << endl;
                marea = max(marea,area);
            }
        }
    }
    out << marea << endl;
}
