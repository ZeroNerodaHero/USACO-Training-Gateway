#include <iostream>
#include <fstream>
using namespace std;
int N, M, C;
int tot(int ar[]){
    total = 0;
    for(int i = 0; i < N; i++){
        total += ar[i];
    }
    return total;
}

int bin(int ar[]){
    int l = 0, r = tot(ar);
    while(l < r){
        int mid= (l+r)/2;
        int longest = 0, group = 0;
        for(int i = 0; i < N; i++){
            if(n = 
        }
    }
}
// 1 1 3 4 10 14
int main(){
    std::ifstream in("subset.in");
    std::ofstream out("subset.out");
    in >> N >> M >> C;
    int a[N];
    for(int i = 0;i < N; i++){
        in >> ar[i];
    }
    std::sort(ar,ar+N);
    std::cout << bin(ar);
}
