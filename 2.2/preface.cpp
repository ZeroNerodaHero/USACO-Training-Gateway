/*
ID: billy
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int letter[7] = {1,5,10,50,100,500,1000};
char letter1[7] = {'I','V','X','L','C','D','M'};
int total[7];

int main(){
    std::ifstream in("preface.in");
    std::ofstream out("preface.out");
    int N;
    in >> N;
    
    for(int i = N; i >= 0; i--){
        int j = i;
        int p = 0;
        while(j){
            int k = j%10;
            j /= 10;
            if(k == 9){
                total[p]++;
                total[p+2]++;
                k = 0;
            }
            if(k >= 5){
                total[p+1]++;
                k -= 5;
            }
            if(k == 4){
                total[p]++;
                total[p+1]++;
                k = 0;
            }
            total[p] += k;
            p += 2;
        }
    } 
    for(int i = 0; i < 7; i++){
        if(total[i]){
            cout << letter1[i] << ' ' << total[i] << endl;
            out << letter1[i] << ' ' << total[i] << endl;
        }
    }
}

