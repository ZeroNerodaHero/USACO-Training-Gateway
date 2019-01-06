/*
ID: billy
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
std::ifstream in("concom.in");
std::ofstream out("concom.out");
int N,lx;
int com[101][101];
int dp[101][101];

void print()
{
    for(int i = 1; i <= lx; i++){
        for(int j = 1; j <= lx; j++){
            std::cout << dp[i][j] << ' ';
        } std::cout << endl;
    }
}

bool isown() 
{
    bool update = false;
    for(int i = 1; i <= lx; i++){
        for(int j = 1; j <= lx; j++){
            if (dp[i][j] > 50) continue;
            int total = 0;
            for(int k = 1; k <= lx; k++){
                if(dp[i][k] > 50){
                    total+= com[k][j];
                }
            }        
            if(total > 50){
                dp[i][j] = total;
                update = true;
            }
        }
    }
    return update;
}

void print1()
{
    for(int i = 1; i <= lx; i++){
        for(int j = 1; j <= lx; j++){
            if((dp[i][j]>50) && (i != j)) out << i << ' ' << j << endl;
        } 
    }
}

int main(){
    in >> N;
    for(int i = 0; i < N; i++){
        int a,b,c;
        in >> a >> b >> c;
        lx = max(max(lx,a),b);
        com[a][b] = c;
        dp[a][b] = c;
    }
    for(int i = 1; i <= lx; i++){
        dp[i][i] = 100;
    }
    //print();
    int count = 0;
while(isown()){count++;};
    std::cout << count << endl;
/*
    for(int i = 1; i <= lx; i++){
        for(int j = 1; j <= lx; j++){
            if(isown(i,j) && i != j) out << i << ' ' << j << endl;
        } 
    }
*/
    print1();
}
