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

bool best(int mid){
    int b[N];
    for(int i = 0; i < N; i++){
        b[i] = a[i];
    }
    for(int i = mid-1; i >= 0; i--){
        int bi = 99999, ind = 51;
        for(int j = 0; j < N; j++){
            if(ar[i] > b[j]) continue;
            if(b[j] - ar[i] < bi){
                bi = b[j]-ar[i];
                ind = j;
            }
        }
        if(ind == 51) return false;
        b[ind] = bi;
    }
    return true;
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
    }
    sort(ar,ar+R);
    int i = 0;
    for(; i < R; i++){
        tar += ar[i];
        if(tar > t) break;
    }
//    cout << R << '-' << i << endl;
    R = i;
    int l = 0, r= R;
    while(l < r){
        int mid = (l+r+1)/2;
//        cout << l << '-' << r << '-' <<  mid << endl;

        if(best(mid)) l = mid;
        else r = mid-1;
    }
    out << l << endl;
}
