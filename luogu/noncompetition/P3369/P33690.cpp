#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;

struct Treap{
    int cnt=0,root=0;
    struct Node{
        int ls,rs; //左儿子，右儿子
        int val,pri; //键值，优先级 ，小根堆
        int siz; //子树大小
        Node(int v=0,int p=0):val(v),pri(p),siz(1),ls(0),rs(0){}
    };
    vector<Node> t;
    Treap(int n) {
        t.assign(n+1,Node());
        t[0].siz=0;
    }

    void update(int x){t[x].siz=t[t[x].ls].siz+t[t[x].rs].siz+1;}

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

    void insert(int &x,int val){
        if(!x){++cnt;x=cnt;t[x]=Node(val,rand());return ;}
        t[x].siz++;
        if(val <= t[x].val){
            insert(t[x].ls,val);
            if(t[t[x].ls].pri < t[x].pri) rotate(x,0);
        }
        else{
            insert(t[x].rs,val);
            if(t[t[x].rs].pri > t[x].pri) rotate(x,1);
        }
        update(x);
    }

    void del(int &x,int val){
        t[x].siz--;
        if(val == t[x].val){
            if(t[x].ls==0 && t[x].rs==0) {x=0;return ;} //叶子节点，直接删除
            if(t[x].ls==0 || t[x].rs==0) {x=t[x].ls+t[x].rs;return ;} //只有一个儿子，直接删除
            if(t[t[x].ls].pri < t[t[x].rs].pri) { 
                rotate(x,0),del(t[x].rs,val);return ;
            }
            else {
                rotate(x,1),del(t[x].ls,val);return ;
            }
        }
        if(val <= t[x].val) 
            del(t[x].ls,val);
        else 
            del(t[x].rs,val);
        update(x);
    }

    int rank(int x,int val) { // val 的排名
        if(x==0) return 0;
        if(val <= t[x].val) return rank(t[x].ls,val);
        else return t[t[x].ls].siz+1+rank(t[x].rs,val);
    }

    int kth(int x,int k){ // 排名为 k 的值
        if(k==t[t[x].ls].siz+1) return t[x].val;
        if(k <= t[t[x].ls].siz) return kth(t[x].ls,k);  //在左子树
        else return kth(t[x].rs,k-t[t[x].ls].siz-1);
    }

    int pre(int x,int val){ //val 的前驱
        if(x==0) return 0;
        if(val <= t[x].val) return pre(t[x].ls,val);
        int tmp=pre(t[x].rs,val);
        if(tmp==0) return t[x].val;
        else return tmp;
    }

    int nxt(int x,int val){ //val 的后继
        if(x==0) return 0;
        if(val >= t[x].val) return nxt(t[x].rs,val);
        int tmp=nxt(t[x].ls,val);
        if(tmp==0) return t[x].val;
        else return tmp;
    }
};


int main(){
    freopen("P3369.in","r",stdin);
    freopen("P33690.out","w",stdout);
    srand(time(0));
    int Q; scanf("%d",&Q);
    Treap T(Q);     
    int op,x;
    while(Q--){
        scanf("%d%d",&op,&x);
        if(op==1) T.insert(T.root,x);
        if(op==2) T.del(T.root,x);
        if(op==3) printf("%d\n",T.rank(T.root,x)+1);
        if(op==4) printf("%d\n",T.kth(T.root,x));
        if(op==5) printf("%d\n",T.pre(T.root,x));
        if(op==6) printf("%d\n",T.nxt(T.root,x));
    }
    return 0;
}