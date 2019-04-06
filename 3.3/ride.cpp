/*
ID: billy
PROG: shopping
LANG: C++11
*/
#include <iostream>
#include <unordered_map>
#include <cstring>
#include <fstream>
using namespace std;
std::ifstream fin("shopping.in");
std::ofstream fout("shopping.out");

int dp[6][6][6][6][6];
int o[105][5];
int val[105];
int w[5];
unordered_map<int,int> m;

int getid(int i){
    static int c = 0;
    if(m.find(i) == m.end()){
        m[i] = c ++; 
    }
    return m[i];
}

int s, q;

void print(){
    cout << s << ' ' << q << endl;
    for(int i = 0; i < s + q; i++){
        cout <<i << " of: ";
        for(int j = 0; j < 5; j++){
            cout << o[i][j] << ' ';
        }
        cout << val[i] << endl;
    }

    cout << "total " << endl << endl;
    for(int i = 0; i < 5; i++){
        cout << w[i] << endl;
    }
}

int solve(){
    memset(dp,0x1F,sizeof(dp));
    dp[0][0][0][0][0] = 0;

    for(int a = 0; a <= w[0]; a++){
        for(int b = 0; b <= w[1]; b++){
            for(int c = 0; c <= w[2]; c++){
                for(int d = 0; d <= w[3]; d++){
                    for(int e = 0; e <= w[4]; e++){
                        for(int i = 0; i < s+q; i++){
                            if(a >= o[i][0] && b >= o[i][1] && c >= o[i][2] && d >= o[i][3] && e >= o[i][4]){
//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
                                dp[a][b][c][d][e] = min(dp[a][b][c][d][e],
                                                        dp[a-o[i][0]][b-o[i][1]][c-o[i][2]][d-o[i][3]][e-o[i][4]]+val[i]);
                            }
                        }
//cout << dp[a][b][c][d][e] << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
                    }
                }
            }
        }
    }  
    return dp[w[0]][w[1]][w[2]][w[3]][w[4]]; 
}

int main(){
    fin >> s;
    for(int i = 0; i < s; i++){
        int n;
        fin >> n;
        for(int j = 0; j < n; j++){
            int K, C; 
            fin >> C >> K;
            int c =  getid(C);
            o[i][c] = K;
        }
        fin >> val[i];
    }
    fin >> q;
    for(int i = 0; i < q; i++){
        int c, k,p;
        fin >> c>> k >>p;
        int j = getid(c);
        w[j] = k;
        o[s+i][j] = 1;
        val[s+i] = p;
    }
 //   print();
    fout << solve() << endl;
}
