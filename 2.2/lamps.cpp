/*
ID: billyz43
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N, total = 0;
int choice1(int combo){
    int pick = 63;
    for(int i = 1;combo != 0; i++){
        int j = combo & 1;
        combo = combo >> 1;
        //111111 101010 010101 100100
        if(j && i == 1) pick = pick ^ 0x3F; 
        if(j && i == 2) pick = pick ^ 0x2A; 
        if(j && i == 3) pick = pick ^ 0x15; 
        if(j && i == 4) pick = pick ^ 0x24; 
    }
    return pick;
}

int choice(int combo){
    int pick = 63;
    int com[4] = {0x3F,0x2A,0x15,0x24};
    for(int i = 0; i < 4; i++){
        if(combo & 1) pick ^= com[i];
        combo >>= 1;
    }
    return pick;
}

int bit(int n){
    int count = 0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}

int bit1(int n){
    int count = 0;
    while(n){
        if(n&1)count++;
        n = n >> 1;
    }
    return count;
}

int main(){
    ifstream in("lamps.in");
    ofstream out("lamps.out");

    int C;
    in >> N >> C;
    int con,final = 0, used = 0;
    while(1){
        in >> con;
        if(con == -1) break;
        con = (con-1)%6;
        final |= 1<<(5-con);
    }
    while(1){
        in >> con;
        if(con == -1) break;
        con = (con-1)%6;
        used |= 1<<(5-con);
    }
    int ar[16];
    int cnt = 0;
    cout << "final " << final << endl;
    cout << "used " << used << endl;

    for(int i = 0; i < 16; i++){
        int end =  choice(i);
        int bits = bit(i);
        if(bits > C || bits%2 != C%2){
            continue;
        }       
        if((end & final) != final || (end & used) != 0){
            continue;
        }
        ar[cnt++] = end;
    }
    sort(ar,ar+cnt);
    for(int i = 0; i < cnt; i++){
        for(int j =0; j < N; j++){
            out << (ar[i]>>(5-(j%6)) & 1);
        } out << endl; 
    }
    if(cnt == 0) out << "IMPOSSIBLE\n";
}
