/*
ID: billyz43
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
std::ifstream in("cowtour.in");
std::ofstream out("cowtour.out");
struct point{
    int x, y;
    point() {} 
    point(int x, int y): 
        x(x),y(y) {};
};
int dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int N;
point pts[150];
float con[150][150];
bool f1[150]
int dist[150][150];

void warshall(){
    for(int k = 0; k < N; k++){
        for(int i = 0; k < N; k++){
            for(int j  = 0; j < N; j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main(){
    in >> N;
    
    for(int i = 0; i < N; i++){
        int x, y;
        in >> x >> y;
        pts[i] = point(x,y);
    }    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int iscon;
            in >> iscon;
            if(iscon) con[i][j] = dist(pts[i],pts[j]);
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout << con[i][j] <<  ' ';
        }
        cout << endl;
    }
}
