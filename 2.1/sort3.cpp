/*
ID: billyz43
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}   

int cnt[4];
int main(){
    std::ifstream in("sort3.in");
    std::ofstream out("sort3.out");
    
    int N;
    in >> N;
    int ar[N];
    for(int i = 0; i < N; i++){
        in >> ar[i];
        cnt[ar[i]]++;
    }
    for(int i = 1; i < 4; i++){
        cnt[i] += cnt[i-1]; 
    }
    int l = cnt[1], r = N-1;
    int swaps = 0;
    //print(ar,N);
    for(int i = 0; i < cnt[1]; i++){
        if(ar[i] == 2){
            for(; l <= r; l++){
                if(ar[l] == 1){
                    swap(ar[i],ar[l]);
                    swaps++;
                    break;
                }
            }        
        } 
        if(ar[i] == 3){
            for(; r >= l; r--){
                if(ar[r] == 1){
                    swap(ar[i],ar[r]);
                    swaps++;
                    break;
                }
            }        
        }
    }
    //print(ar,N);
    //std::cout << cnt[1] <<  ' ' << cnt[2] << endl;;
    //std::cout << swaps << endl;
    for(int i = cnt[1]; i < cnt[2]; i++){
        if(ar[i] != 2) swaps++;
    }
    out << swaps << endl;
    return 0;
}

