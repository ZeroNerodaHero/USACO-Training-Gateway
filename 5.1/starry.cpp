/*
ID: billyz43
PROG: starry
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <utility>
using namespace std;
std::ifstream in("starry.in");
std::ofstream out("starry.out");
int W, H;
string sky[100];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,1,0,-1};

struct star{
    int w, h;
    bool s[100][100];
};
vector<star> v;
bool visited[100][100];

void print(){
    for(int i = 0; i < H; i++){
        cout << sky[i] << endl;
    }
    cout << endl;
}

void print(star& s){
    cout << "w " << s.w << endl;
    cout << "h " << s.h << endl;
    for(int y = 0; y <= s.h; y++){
        for(int x = 0; x <= s.w; x++){
            cout << s.s[y][x];
        }
        cout << endl;
    }
    cout << endl;
}

bool cmp(star& s1, star& s2){
    for(int y = 0; y <= s1.h; y++){
        for(int x = 0; x <= s1.w; x++){
            if(s1.s[y][x] != s2.s[y][x]){
                return false;
            }
        }
    }
    return true;
}

bool cmp1(star& s1, star& s2){
    for(int x = 0; x <= s1.w; x++){
        for(int y = 0; y <= s1.h; y++){
            if(s1.s[y][x] != s2.s[x][y]){
                return false;
            }
        }
    }
    return true;
}

void mirror(star& s){
    for(int y = 0; y <= s.h; y++){
        for(int l = 0,r = s.w; l < r; l++,r--){
            swap(s.s[y][l],s.s[y][r]);
        }
    }
}

void flip(star& s){
    for(int x = 0; x <= s.w; x++){
        for(int l = 0,r = s.h; l < r; l++,r--){
            swap(s.s[l][x],s.s[r][x]);
        }
    }
}

bool same(star& s1, star& s2){
    if(s1.h == s2.h && s1.w == s2.w){
        if(cmp(s1,s2)){
            return true;
        }
        mirror(s1);
        if(cmp(s1,s2)){
            return true;
        }
        flip(s1);
        if(cmp(s1,s2)){
            return true;
        }
        mirror(s1);
        if(cmp(s1,s2)){
            return true;
        }
    }
    if(s1.h == s2.w && s1.w == s2.h){
        if(cmp1(s1,s2)){
            return true;
        }
        mirror(s1);
        if(cmp1(s1,s2)){
            return true;
        }
        flip(s1);
        if(cmp1(s1,s2)){
            return true;
        }
        mirror(s1);
        if(cmp1(s1,s2)){
            return true;
        }       
    }
    return false;
}

int bfs(int sx, int sy){
    memset(visited,0,sizeof(visited));
    queue<pair<int,int> > q;
    int x0 = sx, y0 = sy, x1 = sx, y1 = sy;
    q.push(make_pair(sx,sy));
    visited[sy][sx] = true;

    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();

        //cout << "tmp " << tmp.second << ' ' << tmp.first << endl;

        for(int i = 0; i < 8; i++){
            int x = dx[i] + tmp.first;
            int y = dy[i] + tmp.second;
            if(x >= 0 && x < W && y >= 0 && y < H && sky[y][x] == '1'&& 
               !visited[y][x]){
                visited[y][x] = true;
                q.push(make_pair(x,y));
                x0 = min(x0,x);
                y0 = min(y0,y);
                x1 = max(x1,x);
                y1 = max(y1,y);
            }
        } 
    }
    star st;
    st.w = x1-x0, st.h = y1-y0;
    for(int x = 0; x <= st.w; x++){
        for(int y = 0; y <= st.h; y++){
            st.s[y][x] = visited[y0+y][x0+x];
        }
    }
 //   print(st); 
    for(int i = 0; i < v.size(); i++){
        if(same(st,v[i])){
            return i;
        }
    }
    v.push_back(st);
    return v.size()-1;
}

void bfs2(int sx,int sy, char c){
    queue<pair<int,int> > q;
    sky[sy][sx] = c;
    q.push(make_pair(sx,sy));

    while(!q.empty()){
        pair<int,int> tmp = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int x = dx[i] + tmp.first;
            int y = dy[i] + tmp.second;
            if(x >= 0 && x < W && y >= 0 && y < H &&
               sky[y][x] == '1'){
                sky[y][x] = c;
                q.push(make_pair(x,y));
            }
        } 
    }
}

int main(){
    in >> W >> H;
    for(int i = 0; i < H; i++){
        in >> sky[i];
    }

    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            if(sky[y][x] == '1'){
                int c = bfs(x,y);
                bfs2(x,y,'a'+c); 
            }
        }
    }

    //print();

    for(int i = 0; i < H; i++){
        out << sky[i] << endl;;
    }
}
