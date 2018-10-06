/*
ID: NomNom
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int R;
int v[1000][1000];

int dfs(int row, int pos,int sum){
    if(row+1 > R) return sum+v[row][pos];
    int j = sum + v[row][pos];
    return std::max(dfs(row+1,pos,j), dfs(row+1,pos+1,j));
}

int main(){
    std::ifstream in("numtri.in");
    std::ofstream out("numtri.out");
    in >> R;
    //int v[R][R];
    for(int i = 0; i < R; i++){
        for(int j = 0; j <= i; j++){
            int n;
            in >> n;
            v[i][j] = n;
        }
    }
    out << dfs(0,0,0)<<endl;
    return 0;      
}

