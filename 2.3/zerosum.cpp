/*
ID: billy
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
std::ifstream in("zerosum.in");
std::ofstream out("zerosum.out");
int N;

void run(int cur, int sum,int prev,int tot,int sign,string s){
    if(sign == 0){
        sum -= prev*tot;
        tot = tot*10+cur;
        sum += prev* tot;
    }
    else{
        sum += sign*cur;
        tot = cur;
        prev = sign;
    }

    if(cur == N){
        if(sum == 0) out << s << endl;
        return; 
    }
    run(cur+1,sum,prev,tot,0,s+" "+char(cur+1+'0'));
    run(cur+1,sum,prev,tot,1,s+"+"+char(cur+1+'0'));
    run(cur+1,sum,prev,tot,-1,s+"-"+char(cur+1+'0'));
}

int main(){
    
    in >> N;

    run(1,0,10,1000,1,"1");
}


//generate a list
