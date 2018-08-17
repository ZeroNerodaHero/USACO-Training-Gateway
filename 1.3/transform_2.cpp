/*
ID: nomnom
PROG: transform
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
#define done(x) do{out << x << endl; return 0;}while(0)

struct block{
    int n;
    char c[10][10];
    char tmp[10][10];
    block(int n): n(n) {};
    bool operator == (const block o) const{
        for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
                if(c[i][j]!= o.c[i][j]) return false;
            }
        }
        return true;       
    }  
    block& rot(){
        for(int i = 0; i < n; i++){
            int col = n-i-1;
            for(int j = 0; j < n; j++){
                tmp[j][col] = c[i][j];            
            }
        }    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                c[i][j] = tmp[i][j];
            }
        }
        return *this;
    }

    block& reflect(){
        for(int j = 0; j < n; j++){
            int col = n-j-1;
            for(int i = 0; i < n; i++){
                tmp[i][col] = c[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                c[i][j] = tmp[i][j];
            }
        }
        return *this;
    }
    void fill(ifstream& in){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                in >> c[i][j];
            }
        }
    }
};

int main(){
    ifstream in("transform.in");
    ofstream out("transform.out");

    int N;
    in >> N;
    block a(N), b(N);
    a.fill(in);
    b.fill(in);
    
    int t = 7;
    if(a.rot() == b) t = 1;
    else if(a.rot() == b) t = 2;
    else if(a.rot() == b) t = 3;
    else if(a.rot().reflect() == b) t = 4;
    else if(a.rot() == b) t = 5;
    else if(a.rot() == b) t = 5;
    else if(a.rot() == b) t = 5;

    else if(a.rot().reflect() == b)t = 6;
    out << t << endl;
    return 0;    
}
