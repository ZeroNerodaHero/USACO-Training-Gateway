/*
ID: billyz43
PROG: beads
LANG: C++
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
string s;

int nbreak(int i, int dir=1){
    char color = s[i];
    int count = 0;
    if (dir == -1) i--;

    for(int j = 0; j < N; j++){
        if(s[i%N] != 'w' && s[i%N] != color) break;
        i+=dir; count++;
    }

    return count;
}

int main(){
    std::ifstream in("beads.in");
    std::ofstream out("beads.out");
 
    in >> N >> s;

    int i = 0;
    for(; i < N; ++i){
        if(s[i] != 'w') break;
    }
    int prev, cur = nbreak(i);
    if(cur == N){
        out << N << endl;
        return 0;
    }
    std::cout << "i-\t"<< i << std::endl;
    std::cout << "cur-\t"<< cur << std::endl;
    int big = 0;
    while(i < N){
        prev = cur + nbreak(i,-1);
        i += cur;
        cur = nbreak(i);
cout << i << ": "<<prev << "-" << cur << endl;
        big = max(prev + cur, big);
    }       
    if(big > N) big = N;
    cout << big << endl;
    out << big << endl;
}
