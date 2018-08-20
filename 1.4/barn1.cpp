/*
ID: NomNom
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <fstream>
#include <functional>
using namespace std;

int main(){
    std::ifstream in("barn1.in");
    std::ofstream out("barn1.out");

    int M,S,C;
    in >> M >> S >> C;
    std::priority_queue<int> gap; 
    int stall[C];
    for(int i = 0; i < C; i++){
        in >> stall[i];
    }
    std::sort(stall,stall+C);
    for(int i = 1; i < C; i++){
        int diff = stall[i]-stall[i-1]-1;
        if(diff){
            gap.push(diff);
        }
    }

    S = stall[C-1];
    S -= stall[0]-1;
    while(M != 1 && !gap.empty()){
        int tmp = gap.top();
        gap.pop();
        S -= tmp;
        M--;
    }
    out << S << endl;
    return 0;
}
