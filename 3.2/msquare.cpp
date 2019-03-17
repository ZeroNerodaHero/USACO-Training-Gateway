/*
ID: billy
PROG: msquare
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#define INF 0x7F7F7F
using namespace std;
std::ifstream in("msquare.in");
std::ofstream out("msquare.out");
const int st = 01234567;
unordered_map<int,int> m;

const int O1 = 07777,O2 = 0770077,O3 = 07070707;
int op0(int a){
    a = ((a&O1)<<12)|(a>>12);
    a = ((a&O2)<<6)|((a>>6)&O2);
    a = ((a&O3)<<3)|((a>>3)&O3);
    return a;
}

const int O4 = 0777,O5 = 07;
int op1(int a){
    a = ((a&O4)<<3)|(((a>>15)&O4)<<12)|((a>>9)&O5)|(((a>>12)&O5)<<21);
    return a;
}

const int O6 = 070077007,O7=07000700;
int op2(int a){
    a = (a&O6)|((a&O7)>>3)|(((a>>3)&O5)<<18)|(((a>>15)&O5)<<6);
    return a;
}

int main(){
    int f = 0;
    for(int i = 0; i < 8; i++){
        int a;
        in >> a;
        f<<=3;
        f |= (a-1);
    }

    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int tmp = q.front(); 
        q.pop();
        
        if(tmp == f){
            break;
        }
        int ar[3];
        ar[0] = op0(tmp);
        ar[1] = op1(tmp);
        ar[2] = op2(tmp);
        for(int i = 0; i < 3; i++){
            if(m.find(ar[i]) == m.end()){
                m[ar[i]] = (tmp<<2)|i;
                q.push(ar[i]);
            }
        }
    }
    
    int c = 0;
    stack<char> s;
    while(f != st){
        c++;
        f = m[f];
        s.push('A'+(f&3));
        f >>= 2; 
    }
    out << c << endl;
    c = 0;
    while(!s.empty()){
        if(c == 60){
            cout << endl;
            c = 0;
        }
        out << s.top();
        s.pop();
        c++;   
    }
    out << endl;
/*
    int i = op0(st);
    cout << i << endl;
    cout << 076543210 << endl;
    i = op1(st);
    cout << i << endl;
    cout << 030125674 << endl;
    i = op2(st);
    cout << i << endl;
    cout << 06134257 << endl;
*/   
    return 0;
}

