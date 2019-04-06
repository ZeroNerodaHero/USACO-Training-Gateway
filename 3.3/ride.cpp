/*
ID: billy
PROG: shopping
LANG: C++11
*/
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;
std::ifstream fin("shopping.in");
std::ofstream fout("shopping.out");

int dp[5][5][5][5][5];
int o[105][5];
int val[105];
int w[5];
unordered_map<int,int> m;

int getid(int i){
    static int c = 0;
    if(m.find(i) == m.end()){
        m[i] = c ++; 
    }
    return m[i];
}

int s, b;

void print(){
    cout << s << ' ' << b << endl;
    for(int i = 0; i < s + b; i++){
        cout << "of " << i << ' ';
        for(int j = 0; j < 5; j++){
            cout << o[i][j] << ' ';
        }
        cout << val[i] << endl;
    }

    cout << "total " << endl << endl;
    for(int i = 0; i < 5; i++){
        cout << w[i] << endl;
    }
}


int main(){
    fin >> s;
    for(int i = 0; i < s; i++){
        int n;
        fin >> n;
        for(int j = 0; j < n; j++){
            int K, C; 
            fin >> C >> K;
            int c =  getid(C);
            o[i][c] = K;
        }
        fin >> val[i];
    }
    fin >> b;
    for(int i = 0; i < b; i++){
        int c, k,p;
        fin >> c>> k >>p;
        int j = getid(c);
        w[j] = k;
        o[s+i][j] = 1;
        val[s+i] = p;
    }
    print();
}
