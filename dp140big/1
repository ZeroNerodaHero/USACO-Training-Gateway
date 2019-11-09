/*
ID: billyz43
PROG: zoo
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <list>
#include <cmath>
#define INF 0x3F3F3F3F
std::ifstream in("zoo.in");
std::ofstream out("zoo.out");
using namespace std;
struct node{
    int s,h,l,rh,rl;
    int like[5],hate[5];
    bool operator < (const node& o) const{
        return s < o.s;
    }
};

int N,C,F,H,ans;
node ch[50002];
vector<int> ha;
vector<int> rem;

void dfs(int i){
    if(i == H){
        int cur = 0;
        for(int k = 0; k< C; k++){

#if 0
if((rem.size() == 1) && (rem[0] ==13)) {
    cout << "\t" <<ch[k].rh << ' ' << ch[k].rl << ' ' << ch[k].h << ' ' << ch[k].l << endl;
}
#endif

            if(ch[k].rh > 0) cur++;
            else{
                if(ch[k].rl < ch[k].l){
                    cur++;
                }
            }
        }   
        ans = max(cur,ans);
        return;
    }

    dfs(i+1);

    for(int j = 0; j< C; j++){
        for(int k = 0; k < ch[j].h; k++){
            if(ch[j].hate[k] == ha[i]){
                ch[j].rh++;
            }
        }
        for(int k = 0; k < ch[j].l; k++){
            if(ch[j].like[k] == ha[i]){
                ch[j].rl++;
            }
        }
    }

    rem.push_back(ha[i]);
    dfs(i+1);
    rem.pop_back();
    for(int j = 0; j< C; j++){
        for(int k = 0; k < ch[j].h; k++){
            if(ch[j].hate[k] == ha[i]){
                ch[j].rh--;
            }
        }
        for(int k = 0; k < ch[j].l; k++){
            if(ch[j].like[k] == ha[i]){
                ch[j].rl--;
            }
        }
    }
}

void print(){
    for(int i = 0; i < C; i++){
        cout << ch[i].s << ' ' << ch[i].h << ' ' << ch[i].l << ' ';
        for(int j = 0; j < ch[i].h; j++){
            cout << ch[i].hate[j] << ' '; 
        } 
        for(int j = 0; j < ch[i].l; j++){
            cout << ch[i].like[j] << ' '; 
        } 
        cout << endl;
    }
}
int main(){
    in >> N >> C;
    int j = C-1;
    for(int i = 0; i < C; i++){
        int s,h,l,k;
        in >> s >> h >> l;
        if(l == 0){
            k = F++;
        } else{
            k = j--;
        }
        
        //ch[k].s = s-1;
        ch[k].s = s;
        ch[k].l = l;
        ch[k].h = h;
        ch[k].rh = 0;
        ch[k].rl = 0;
        for(int j = 0; j < ch[k].h; j++){
            in >> ch[k].hate[j];
            //ch[k].hate[j]--;
            ha.push_back(ch[k].hate[j]);
        } 
        for(int j = 0; j < ch[k].l; j++){
            in >> ch[k].like[j];
            //ch[k].like[j]--;
        }
    }
    //print();
    //sort(ch,ch+F);
    //sort(ch+F,ch+C);
    sort(ha.begin(),ha.end());
    if(ha.size() > 0) H = 1;
    for(int i = 1; i < ha.size(); i++){
        if(ha[i] != ha[i-1]){
            ha[H] = ha[i];
            H++;
        }
    }
#if 0
    //print();
    cout << H << ": ";
    for(auto i : ha){
        cout << i << ' ';
    }
    cout << endl;
#endif
    dfs(0);
    out << ans << endl;
}
