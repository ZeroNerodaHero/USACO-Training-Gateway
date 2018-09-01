/*
ID: NomNom
PROG: milk
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("milk.in");
    std::ofstream out("milk.out");
    int N;
    in >> N;

    int ar[N]
    for(int i = 0; i < N; i++){
        in >> ar[i];
    }
    sort(ar,ar+N);
    int diff = ar[N-1]-ar[0]
    while(diff > 17){
        int pay = diff - 17;
        int total = (pay/2) + (pay-(pay/2)) * (pay-(pay/2));
    }
    
    return 0;   
}
