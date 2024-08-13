#include<bits/stdc++.h>
using namespace std;

struct Treap{
    int root=0;
    struct Node{
        int ls,rs; //左儿子，右儿子
        int val,pri; //键值，优先级
        int siz; //子树大小
        int lay; //懒标记
        Node(int v=0,int p=0):val(v),pri(p),siz(1),ls(0),rs(0),lay(0){}
    };
    vector<Node> t;
    Treap(int n) {t.assign(n+1,Node());t[0].siz=0;}

    void push_up(int x){t[x].siz=t[t[x].ls].siz+t[t[x].rs].siz+1;}

    void push_down(int x){
        if(t[x].lay){
            swap(t[x].ls,t[x].rs);
            t[t[x].ls].lay^=1; t[t[x].rs].lay^=1;
            t[x].lay=0;
        }
    }

    void split(int x,int k,int &L,int &R){ //排名分裂，返回：L 前 x 个数，R 其他数
        if(x==0){L=R=0;return ;}
        push_down(x);
        if(t[t[x].ls].siz+1 <= k){
            L=x;
            split(t[x].rs,k-t[t[x].ls].siz-1,t[x].rs,R);
        }
        else{
            R=x;
            split(t[x].ls,k,L,t[x].ls);
        }
        push_up(x);
    }

    int merge(int L,int R){
        if(L==0 || R==0) return L+R;
        if(t[L].pri > t[R].pri){
            push_down(L);
            t[L].rs = merge(t[L].rs,R);
            push_up(L);
            return L;
        }
        else{
            push_down(R);
            t[R].ls = merge(L,t[R].ls);
            push_up(R);
            return R;
        }
    }

    void inorder(int x){
        if(x==0) return ;
        push_down(x);
        inorder(t[x].ls);
        printf("%d ",t[x].val);
        inorder(t[x].rs);
    }
};

int main(){
    freopen("P3391.in","r",stdin);
    int n,m; scanf("%d%d",&n,&m);
    Treap T(n);
    for(int i=1;i<=n;i++){
        T.t[i]=Treap::Node(i,rand());
        T.root=T.merge(T.root,i);
    }
    while(m--){
        int l,r; scanf("%d%d",&l,&r);
        int L,R,p; //三颗树
        T.split(T.root,r,L,R);  
        T.split(L,l-1,L,p);
        T.t[p].lay^=1;
        T.root=T.merge(T.merge(L,p),R);
    }
    T.inorder(T.root);
    return 0;
}