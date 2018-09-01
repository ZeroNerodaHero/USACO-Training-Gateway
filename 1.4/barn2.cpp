/*
ID: NomNom
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <functional>
using namespace std;

struct diff{
    int gap, a, b;
    diff(int gap,int a, int b):gap(gap),a(a),b(b) {}
    bool operator < (const diff &o) const{
        return gap < o.gap;
    }
};

int main(){
    std::ifstream in("barn1.in");
    std::ofstream out("barn1.out");

    int M,S,C;
    in >> M >> S >> C;
    std::priority_queue<diff> gap; 
    int stall[C];
    for(int i = 0; i < C; i++){
        int tmp;
        in >> tmp;
        stall[i] = tmp;
        if(i > 0) gap.push(diff(stall[i]-stall[i-1]-1,i-1,i)); 
        std::cout << i << endl;
    }

    while (!gap.empty())
  {
     std::cout << "iiiiiii";
     std::cout << ' ' << gap.top().gap;
     gap.pop();
  }

     std::cout << "iiiiiii";
    S -= stall[0]-1;
    S -= 50-stall[C-1];
    while(M != 0){
        diff tmp = gap.top();
        gap.pop();
        S -= tmp.gap;
        M--;
    }
    out << S << endl;
    return 0;
}
