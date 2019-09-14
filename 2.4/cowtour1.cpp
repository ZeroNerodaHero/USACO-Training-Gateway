/*
ID: billyz43
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#define INF 1e9
#define INF1 (INF-1)
using namespace std;
std::ifstream in("cowtour.in");
std::ofstream out("cowtour.out");
struct point{
    int x, y;
    point() {} 
    point(int x, int y): 
        x(x),y(y) {};
};
int N;
point pts[150];
string con[150];
double d[150][150];
double m[150];

double dist(int i, int j){
    point &a = pts[i],&b = pts[j];
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline bool notINF(double a){
    return abs(a-INF) > 1;
}

void print(){
    cout << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << d[i][j] << '\t';
        }
        cout << endl;
    }
}

double warshall(){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j  = 0; j < N; j++){
                if(notINF(d[i][k]) && notINF(d[k][j])){
//                if(d[i][k] != INF && d[k][j] != INF){
                     d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
                }
            }
        }
    }
    //print();
    double big = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(notINF(d[i][j])) {
//            if(d[i][j] != INF){
                m[i] = max(m[i], d[i][j]);
                big = max(big,m[i]);
            }
        }
    }
    cout.precision(6);
    cout << fixed << big << endl;
    double shortest = INF;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(!notINF(d[i][j])){
            //if(d[i][j] == INF){
                double len = m[i] + dist(i,j) + m[j];
                shortest = min(shortest,len);
            }
        }
    }
    return max(shortest,big);
}

int main(){
    in >> N;
    
    for(int i = 0; i < N; i++){
        int x, y;
        in >> x >> y;
        pts[i] = point(x,y);
    }    
    for(int i = 0; i < N; i++){
        in >> con[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(con[i][j] == '1') d[i][j] = d[j][i] = dist(i,j);
            else d[i][j] = d[j][i] = INF;         
        }
    }
    //print();
    out.precision(6);
    out << fixed << warshall() << endl;
}
