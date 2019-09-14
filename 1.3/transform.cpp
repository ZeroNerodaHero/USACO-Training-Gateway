/*
ID: billyz43
PROG: transform
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

#define done(x) do{out << x << endl; return 0;}while(0)

int N;
char a[10][10], b[10][10], tmp[10][10];;

bool isequal(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

void rot(){
    for(int i = 0; i < N; i++){
        int col = N-i-1;
        for(int j = 0; j < N; j++){
            tmp[j][col] = a[i][j];            
        }
    }    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = tmp[i][j];
        }
    }
}

void reflect(){
    for(int j = 0; j < N; j++){
        int col = N-j-1;
        for(int i = 0; i < N; i++){
            tmp[i][col] = a[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = tmp[i][j];
        }
    }
}

int main(){
    std::ifstream in("transform.in");
    std::ofstream out("transform.out");

    in >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> a[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            in >> b[i][j];
        }
    }
    for(int i = 1; i < 4; i++){
        rot();
        if(isequal()) done(i);
    } 
    rot();
    if(isequal()) done(6);
    reflect();
    if(isequal()) done(4);
    for(int i = 0; i < 3; i++){
        rot();
        if(isequal()) done(5);
    }   
    done(7);
}
