/*
ID: billyz43
PROG: spin
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("spin.in");
std::ofstream out("spin.out");

int speed[5], W[5];
int s[5][5],e[5][5];

bool ok(){
    int check[360];
    memset(check,0,sizeof(check));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < W[i]; j++){
            for(int k = 0, st = s[i][j]; k <= e[i][j]; k++,st++){
                if(st == 360) st = 0;
                check[st]++;
            }
        }
    }
    for(int i = 0; i < 360; i++){
        if(check[i] == 5){
            //cout << i << endl;
            return true;
        }
    }
    return false;
}

int main(){
    for(int i = 0; i < 5; i++){
        in >> speed[i] >> W[i];
        for(int j = 0; j < W[i]; j++){
            int t;
            in >> s[i][j] >> e[i][j];
        }
    }
    for(int i = 0; i < 360; i++){
        if(ok()){
            out << i << endl;
            return 0;
        } 
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < W[j]; k++){
                s[j][k] += speed[j];
                if(s[j][k] >= 360){
                    s[j][k] -= 360;
                }
                //cout << j << ' ' << s[j][k] << endl;
            }
        }
    }
    out << "none" << endl;
    return 0;
}

