/*
ID: billyz43
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    std::ifstream in("skidesign.in");
    std::ofstream out("skidesign.out");

    int N;
    in >> N;
    int height[N];
    for(int i = 0; i < N; i++){
        in >> height[i];
    } 
    int count = 999999;
    for(int r = 17,l=0; r < 101; r++,l++){
        int tmp = 0;
        for(int n = 0; n < N; n++){
            if(height[n] < l) tmp += (l-height[n])*(l-height[n]);
            if(height[n] > r) tmp += (height[n]-r)*(height[n]-r);
        }
        count = min(count,tmp);
    }

    out << count << '\n';
    return 0;   
}
