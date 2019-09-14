/*
ID: billyz43
PROG: twofive
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;
std::ifstream in("twofive.in");
std::ofstream out("twofive.out");

bool visited[25];
char ar[28];
int dp[6][6][6][6][6];
int l[5];
int mx[5],my[5];

void print(){
    //for(int i = 0; i < 26; i++) cout << int(ar[i]) << ' '; cout << endl;
    cout << "string " <<  ar << endl;
}

int dfs(int ch){
    int& x = dp[l[0]][l[1]][l[2]][l[3]][l[4]];

    if(x >= 0) return x;
    if(l[0] == 5 && l[1] == 5 && l[2] == 5 && l[3] == 5 && l[4] == 5){
        //print();
        return 1;
    }    

    int v = 0;
    while(visited[ch]) ch++;

//    cout << l[0] << l[1] << l[2]<< l[3] << l[4] << ": " << ch <<endl;
    visited[ch] = true;
    for(int i = 0; i < 5; i++){
        if(l[i] < 5 && (i == 0 || l[i] < l[i-1]) && mx[i] < ch && my[l[i]] < ch){
            //ar[l[i]+5*i] = char(ch+'A');
            int ox = mx[i], oy = my[l[i]];
            mx[i] = ch;
            my[l[i]] = ch;
            l[i]++;
            v += dfs(ch+1);
            mx[i] = ox;
            l[i]--;
            my[l[i]] = oy;
        }
    }
    visited[ch] = false;
    x = v;
    return x;
}

void w(int st[]){
    int sum = 1;
    int k = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            l[i]++;
            for(int ch = 0; ch < 25; ch++){
                if(!visited[ch] && mx[i] < ch && my[j] < ch){
                    visited[ch] = true;
                    mx[i] = ch; 
                    my[j] = ch;
                    memset(dp,-1,sizeof(dp));
                    if(st[k] == ch){
//cout << "use " << char('A'+ch) << endl;
                        break;
                    }
                    int a = dfs(0);
                    sum += a;
//cout << "add " << char('A'+ch) << " " << a << ' ' << sum<< endl;
                    visited[ch] = false;
                }
            }
            k++;
        }
    }
    out << sum << endl;
}

void n(int t){
    t--;
    int k = 0,ch;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            l[i]++;
           for(ch = 0; ch < 25; ch++){
                if(!visited[ch] && mx[i] < ch && my[j] < ch){
                    visited[ch] = true;
                    mx[i] = ch;
                    my[j] = ch;
                    memset(dp,-1,sizeof(dp));
                    int a = dfs(0);
//cout << "try " << char('A'+ch) << " " << a << endl;
                    if(t < a){
//cout << "use " << char('A'+ch) << " " << a << endl;
                        ar[k++] = ch+'A';
                        break;
                    }
                    visited[ch] = false;
                    cout << t << ' ' << a << " t - a " << t-a << endl;;
                    t -= a;
                }
            } 
        }
    }
    out << ar << endl;
}

int main(){
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));

    char c;
    in >> c;
    if(c == 'N'){
        int N; 
        in >> N;
        n(N);
    } else{
        int st[25];
        for(int i = 0; i < 25; i++){
            in >> c;
            st[i] = c-'A';    
        }
        w(st);
    }

    
}
