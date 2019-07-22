/*
ID: billy
PROG: fence8
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
std::ifstream in("fence8.in");
std::ofstream out("fence8.out");
using namespace std;
int N,R;
int a[50];
int ar[1023];

void best(){
    int big = 0;
    while(1){
        int b[N];
        for(int i = 0; i < N; i++){
            b[i] = a[i];
        }
        int tot = 0;
        for(int i = R-1; i >= 0; i--){
            int bi = 99999, ind = 51;
            for(int j = 0; j < N; j++){
                if(ar[i] > b[j]) continue;
                if(b[j] - ar[i] < bi){
                    bi = b[j]-ar[i];
                    ind = j;
                }
            }
            if(ind == 51) break;;
            b[ind] = bi;
            tot++;
        }
        big = max(big,tot);
        if(big == R) break;      
        R--;
    }
    out << big << endl;
}

int main(){
    int t = 0, tar =0;
    in >> N;
    for(int i = 0; i < N; i++){
        in >> a[i];
        t += a[i];
    }
//    cout << "t\t" << t << endl;
    in >> R; 
    for(int i = 0; i < R; i++){
        in >> ar[i];
        tar += ar[i];
    }
    sort(ar,ar+R);
//    cout << "tar\t" << tar << endl;
    while(tar > t){
        tar -= ar[--R];
    }
//    cout << "f R " << R << endl;
//    cout << "tar\t" << tar << endl;

    best();
}
