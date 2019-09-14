/*
ID: billyz43
PROG: ratios
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("ratios.in");
std::ofstream out("ratios.out");

int val[10000];

int main(){
    int x,y,z;
    int val[3][3];
    int s1,s2,s3,sd;

    in >> x >> y >> z;
    for(int i = 0; i < 3; i++){
        in >> val[i][0] >> val[i][1] >> val[i][2];
    }

    for(int s = 1; s <= 297; s++){
        for(int j = 0; j < 100 && j <= s; j++){
            //for(int k = 0; k < 100; k++){
            for(int k = max(0,s-j-99); k < 100; k++){
                int i = s-j-k;
                //cout << s << ' ' << i << ' ' << j << ' ' << k << endl;
                if(i < 0 || i >= 100) break;
                //if(i < 0 || i >= 100) continue;
                int t1 = i * val[0][0] + j * val[1][0] + k * val[2][0];
                int t2 = i * val[0][1] + j * val[1][1] + k * val[2][1];
                int t3 = i * val[0][2] + j * val[1][2] + k * val[2][2];
                int c;
                if(x != 0){
                    if(t1%x != 0) continue;
                    c = t1/x;
                }
                else if(y != 0){
                    if(t2%y != 0) continue;
                    c = t2/y;
                }
                else{
                    if(t3%z != 0) continue;
                    c = t3/z;
                }
                if(t1*y == t2*x && t2*z == t3*y && t1*z == t3*x){
                    out << i << ' ' << j << ' ' << k << ' ' << c << endl;
                    return 0;
                }
            }
        }
    }    
    out << "NONE\n";
}

