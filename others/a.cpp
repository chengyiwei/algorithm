#include<bits/stdc++.h>
using namespace std;



struct Treap{
    struct Node{
        int ls,rs; //左儿子，右儿子
        int val,pri; //键值，优先级
        int siz; //子树大小
        Node(int v=0,int p=0):val(v),pri(p),siz(1),ls(0),rs(0){}
    };
    vector<Node> t;
    Treap(int n) {t.assign(n+1,Node());}
    void rotate(int &x,int d){ // d=0 右旋，d=1左旋
        int k;
        if(d==1){
            k=t[x].rs;
            t[x].rs=t[k].ls;
            t[k].ls=x;
        }
        else{
            k=t[x].ls;
            t[x].ls=t[k].rs;
            t[k].rs=x;
        }
        t[k].siz=t[x].siz;
        update(x);
        x=k;
    }
};


int main(){}