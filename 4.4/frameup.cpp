/*
ID: billyz43
PROG: frameup
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;
std::ifstream in("frameup.in");
std::ofstream out("frameup.out");
int N,H,W;
int g[30][30];
int con[26][26];
int ind[26];
int cd[128];
char ch[26];

struct rect{
    int tx,ty,bx,by;
    rect(){
        tx = ty = 33;
        bx = by = 0;
    }
};

//struct node
rect frame[26];

int getid(char c)
{
    if (cd[c] == -1) {
        cd[c] = N;
        ch[N++] = c;
    }
    return cd[c];
}


void print(){
    for(int i = 0; i < N; i++){
        cout << "top: " << frame[i].tx << ' ' << frame[i].ty << endl;
        cout << "bot: " << frame[i].bx << ' ' << frame[i].by << endl;
        cout << endl;
    }
}

void printcon(){
    cout << "N \t" << N << endl;
    for(int i = 0; i < N; i++){
        cout << i << '\t';
        for(int j = 0; j < N; j++){
            if(con[i][j] == 1) cout << j << ' ';
        }
        cout << endl;
    }
}

void printin(){
    for(int i = 0; i < N; i++){
        cout << "ind " << i << ' ' << ind[i] << endl;
    }
}

void findcon(){
    for(int i = 0; i < N; i++){
        int cx = frame[i].tx, cy = frame[i].ty;
        while(cx <= frame[i].bx){
            int t = g[frame[i].ty][cx], b = g[frame[i].by][cx];
            if(t != i && con[t][i] == 0){
                con[t][i] = 1;
                ind[i]++;
            }
            if(b != i && con[b][i] == 0){
                con[b][i] = 1;
                ind[i]++;
            }
            cx++;
        }
        while(cy <= frame[i].by){
            int l = g[cy][frame[i].tx],r = g[cy][frame[i].bx];
            if(l != i && con[l][i] == 0){
                con[l][i] = 1;
                ind[i]++;
            }
            if(r != i && con[r][i] == 0){
                con[r][i] = 1;
                ind[i]++;
            }
            cy++;
        }           
    }
    //printcon();
}

string v;
vector<string> ans;
bool visited[26];
void top(int s){
    //cout << "S\t" << s << endl;
    if(s < 0){
        ans.push_back(v);
        return;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i] && ind[i] == 0){
     //       cout << "cur " << i << endl;
            visited[i] = true;
            v[s] = ch[i];
            for(int j = 0; j < N; j++){
                if(con[i][j] == 1) ind[j]--;
            }
            top(s-1);  
            visited[i] = false;
            for(int j = 0; j < N; j++){
                if(con[i][j] == 1) ind[j]++;
            }
        } 
    }
}

int main(){
    in >> H >> W;
    memset(cd,-1,sizeof(cd));

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            char c;
            in >> c;
            if(c == '.'){
                continue;
            }
            g[i][j] = getid(c);;
//            cout << g[i][j];
            if(frame[g[i][j]].ty > i){
                frame[g[i][j]].ty = i;
            }
            if(frame[g[i][j]].tx > j){
                frame[g[i][j]].tx = j;
            } 
            if(frame[g[i][j]].by < i){
                frame[g[i][j]].by = i;
            }
            if(frame[g[i][j]].bx < j){
                frame[g[i][j]].bx = j;
            }
        }
        //cout << endl;
    }    
//    print();
    findcon();
 //   printin();
    v.resize(N);
    top(N-1);
      //  cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(auto& i: ans){
        out << i << endl;
    }
}
