/*
ID: billy
PROG: castle
LANG: C++
*/
#include <iostream>
#include <map>
#include <fstream>
std::ifstream in("castle.in");
std::ofstream out("castle.out");
using namespace std;
int M, N;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};
int dd[4] = {2,4,1,8};
const char dc[] = "NE";
int room[50][50];
map<int,int> sizes;

int visited[50][50];
void flood(int i, int j, int num){
    visited[i][j] = num;
    sizes[num]++;
    for(int c = 0; c < 4; c++){
        if(room[i][j] & dd[c]) continue;
        int x = i+dx[c], y = j+dy[c];
        if(visited[x][y] == -1){
            flood(x,y,num);
        }
    }
}

void dfs(){
    int num = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = -1;
        }
    } 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j] == -1){
                 flood(i,j,num++);
                 //std::cout << i << "," << j << "- "<< room[i][j] << '\n';
            }
        }
    }
    int big = 0;
    //for(auto i = sizes.begin(); i != sizes.end(); i++){
    for(auto& i : sizes){
        //cout << i.second << endl;
        big = std::max(big,i.second);
    }
    out << num << endl;
    out << big << endl;
}

void wall(){
    int bigx, bigy, side, big = 0;
    for(int j = 0; j < M; j++){
        for(int i = N-1; i >= 0; i--){
            for(int k = 0; k < 2; k++){
                if(room[i][j] & dd[k]){
                    int x = i+dx[k], y = j + dy[k];
                    if(x >= 0 && x < N && y >= 0 && y < M){
                        int &a = visited[i][j], &b = visited[x][y];
                        if(a != b){
                            if(big < sizes[a] + sizes[b]){
                                big = sizes[a] + sizes[b];
                                bigx = i, bigy = j, side = k;
                            }
                        }   
                    }
                }
            }
        }
    }
    out << big << endl;
    out << bigx+1 << ' ' << bigy+1 << ' ' << dc[side] << endl;    
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cout << room[i][j] << ' ';
        } std::cout << endl;
    }
}

int main(){
    in >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            in >> room[i][j];               
        }
    }
    //print();
    dfs();
    wall();
}

