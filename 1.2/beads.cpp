/*
ID: NomNom
PROG: beads
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

void print(char ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

int main(){
    std::ifstream in("beads.in");
    std::ofstream out("beads.out");
    
    int size, necksize = 0;
    in >> size;
    int count[size*2];
    char color[size*2];
    char last;
    in >> last;
    color[necksize] = last;
    count[necksize] = 1;
    for(int i = 1; i < size; i++){
        char bead;
        in >> bead;
        if(bead == last){
             count[necksize]++;
        }
        else{
            necksize++;
            color[necksize] = bead;
            count[necksize] = 1;
        }
        last = bead;
    }

    for(int i = 0; i <= necksize; i++){
        count[i + necksize+1] = count[i];
        color[i + necksize+1] = color[i];
    }
    necksize *= 2;
    print(color,necksize+1);
    int big = count[0], prev = 0;
    for(int i = 0; i <= necksize; i++){
        int cur = count[i];
        char c = color[i];
        if(color[i] == 'w'){
            cur += count[++i];
            c = color[i];
        } else {
            if(i > 0 && color[i-1] == 'w'){
                prev -= count[i-1];
                cur += count[i-1];
            }
        }
        while(i <= necksize && (color[i+1] == 'w' || color[i+1] == c)){
            cur += count[++i];
        }
        big = max(cur+prev,big);
        prev = cur;
    }
    if(big > size){
        big = size;
    }

    std::cout <<  big << std::endl;
    out <<  big << std::endl;
}
