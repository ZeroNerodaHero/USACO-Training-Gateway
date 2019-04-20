/*
ID: billy
PROG: rockers
LANG: C++11
*/
#include <iostream>
#include <fstream>
using namespace std;
std::ifstream in("rockers.in");
std::ofstream out("rockers.out");

struct node{
    char c;
    node *left, *right;
    node(){
        left = right = nullptr;
    }
}

node * build(node* cur, int io, preo){
    cur->c = preo[0];
    preo->left = build(cur->left,substr(1),
}

int post(node * t){
    if(t->left){
        post(t->left);
    }
    if(t->right){
        post(t->right);
    }
    out << t->c;
}

int main(){
    in >> tin >> tpre;
    node* head = nullptr;
    head = build(head,tin,tpre);   
}
