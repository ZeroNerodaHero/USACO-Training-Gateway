/*
ID: billy
PROG: window
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
std::ifstream in("window.in");
std::ofstream out("window.out");
int N;


struct rect{
    bool real;
    int x1,y1,x2,y2;
    rect * prev,* next;
    rect() {}
    rect(int x1,int y1,int x2,int y2):  
        x1(x1),y1(y1),x2(x2),y2(y2) {}
};
rect r[128];

rect * head, * tail;

void print(){
    rect * tmp = head;
    while(tmp != nullptr){
        cout << tmp->x1 << ' ' << tmp->y1 << " : " << tmp->x2 << ' ' << tmp->y2 << " | " << tmp->prev << " " << tmp->next << endl;
        tmp = tmp->next;
    }
}

void w(char a, int x1,int y1,int x2,int y2){
    r[a].x1 = x1;
    r[a].y1 = y1;
    r[a].x2 = x2;
    r[a].y2 = y2;
    
    rect * tmp = &r[a];
    tmp->next = head;
    tmp->prev = nullptr;
    if(head == nullptr){
        head = tail = tmp;
    } else{
        head->prev = tmp;
    }
    head = tmp;
}

void t(char a){
    rect * tmp = &r[a];
    if(tmp == head) return;
    if(tmp == tail){
        tail = tmp->prev;
        tail->next = nullptr;
    } else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    tmp->next = head;
    tmp->prev = nullptr;
    head->prev = tmp;
    head = tmp;
} 

void b(char a){
    rect * tmp = &r[a];
    if(tmp == tail) return;
    if(tmp == head){
        head = tmp->next;
        head->prev = nullptr;
    } else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    tmp->next = nullptr;
    tmp->prev = tail;
    tail->next = tmp;
    tail = tmp;
}

void d(char a){
    rect * tmp = &r[a];
    if(tmp == head && tmp == tail){
        head = tail = nullptr;
    } else if(tmp == head){
        head = head->next;
        head->prev = nullptr;
    } else if(tmp == tail){
        tail = tail->prev;
        tail->next = nullptr;
    } else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
}

void s(char a){
    //print();
    rect tmp = r[a];
    queue<rect> q,q2;
    q.push(r[a]);
    for(rect * cur = tmp.prev; cur != nullptr; cur = cur->prev){
        //cout << "cur " << cur->x1 << ' ' << cur->y1 << " : " << cur->x2 << ' ' << cur->y2 << endl; 
        while(!q.empty()){
            tmp = q.front();
            //cout << "tmp " << tmp.x1 << ' ' << tmp.y1 << " : " << tmp.x2 << ' ' << tmp.y2 << endl; 
            q.pop();

            if(tmp.x1 < cur->x1){
                q2.push(rect(tmp.x1,tmp.y1,min(tmp.x2,cur->x1),tmp.y2));
            }
            if(tmp.x2 > cur->x2){
                q2.push(rect(max(tmp.x1,cur->x2),tmp.y1,tmp.x2,tmp.y2));
            }
            if(!(tmp.x2 < cur->x1 || tmp.x1 > cur->x2)){
                if(tmp.y2 > cur->y2){
                    //cout << "has 3" << endl;
                    q2.push(rect(max(tmp.x1,cur->x1), max(tmp.y1,cur->y2), min(tmp.x2,cur->x2), tmp.y2));
                }
                if(tmp.y1 < cur->y1){
                    //cout << "has 4" << endl;
                    q2.push(rect(max(tmp.x1,cur->x1),tmp.y1,min(tmp.x2,cur->x2),min(tmp.y2,cur->y1)));
                }
            }
            
        }
        q.swap(q2);
    }
    double area = 0;
    while(!q.empty()){
        tmp = q.front();
        q.pop();

        area += (tmp.x2-tmp.x1)*(tmp.y2-tmp.y1);
    }
    double total = (r[a].x2-r[a].x1) * (r[a].y2-r[a].y1);
    //cout << area <<  ' ' << total  << endl;
    double per = area * 100/total;
    out << fixed << setprecision(3) << per << endl;
}

int main(){
    char c,a,f;
    int x1,y1,x2,y2;
    while(true){
        in >> c;
        if(in.fail()) break;
        if(c == 'w'){
            in >> f >> a >> f >> x1 >> f >> y1 >> f >> x2 >> f >>  y2 >> f ;
 //           //cout << "w " << a << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
            w(a,min(x1,x2),min(y1,y2),max(x1,x2),max(y1,y2));
        }
        else{ 
            in >> f >> a >> f;
            //cout << c << ' ' << a << endl;
            if(c == 't') t(a);
            if(c == 'b') b(a);
            if(c == 'd') d(a);
            if(c == 's') s(a);
        }
    }
}
