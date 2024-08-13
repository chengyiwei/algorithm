#include<bits/stdc++.h>
using namespace std;

struct Treap{
    int cnt=0,root=0;
    struct Node{
        int ls,rs; //左儿子，右儿子
        int val,pri; //键值，优先级
        int siz; //子树大小
        Node(int v=0,int p=0):val(v),pri(p),siz(1),ls(0),rs(0){}
    };
    vector<Node> t;
    Treap(int n) {t.assign(n+1,Node());t[0].siz=0;}

    void update(int x){t[x].siz=t[t[x].ls].siz+t[t[x].rs].siz+1;}

    void split(int x,int val,int &L,int &R){
        if(!x){L=R=0;return ;}
        if(val < t[x].val){ //注意这里是 < ，因为当 val == t[x].val 时，也要把 val 放在 L 中
            R=x;
            split(t[x].ls,val,L,t[x].ls);
        }
        else{
            L=x;
            split(t[x].rs,val,t[x].rs,R);
        }
        update(x); //有可能会改变 x 的左右儿子，所以要更新 x 的 siz
    }
    
    int merge(int L,int R){  //合并以 L，R 为根的两棵树,返回合并后的根
        if(L==0 || R==0) return L+R;
        if(t[L].pri > t[R].pri) { // L 的优先级大于 R 的优先级，L 节点为根
            t[L].rs = merge(t[L].rs,R);
            update(L);  //t[L]的右儿子可能改变，所以要更新
            return L;
        }
        else{
            t[R].ls = merge(L,t[R].ls);
            update(R);  //t[R]的左儿子可能改变，所以要更新
            return R;
        }
    }

    void insert(int val){ //插入数字 val
        int L,R;
        split(root,val,L,R);
        ++cnt;t[cnt]=Node(val,rand());
        root=merge(merge(L,cnt),R);
    }

    void del(int val){ //删除数字 val
        int L,R,p;
        split(root,val,L,R); // <= val 的在 L 中，> val 的在 R 中
        split(L,val-1,L,p); // < val 的在 L 中，= val 的在 p 中
        p=merge(t[p].ls,t[p].rs); //删除 p 节点
        root=merge(merge(L,p),R);
    }

    void rank(int val){  //查询 x 的排名
        int L,R;
        split(root,val-1,L,R);
        printf("%d\n",t[L].siz+1);
        root=merge(L,R);
    }

    int kth(int x,int k){
        if(k == t[t[x].ls].siz+1) return x;
        if(k <= t[t[x].ls].siz) return kth(t[x].ls,k);
        else return kth(t[x].rs,k-t[t[x].ls].siz-1);
    }

    void pre(int val){
        int L,R;
        split(root,val-1,L,R);
        printf("%d\n",t[kth(L,t[L].siz)].val);
        root=merge(L,R);
    }

    void nxt(int val){
        int L,R;
        split(root,val,L,R);
        printf("%d\n",t[kth(R,1)].val);
        root=merge(L,R);
    }
};

int main(){
    freopen("P3369.in","r",stdin);
    freopen("P3369_1.out","w",stdout);
    srand(time(0));
    int n;scanf("%d",&n);
    Treap T(n);
    int op,x;
    while(n--){
        scanf("%d%d",&op,&x);
        if(op==1) T.insert(x);
        else if(op==2) T.del(x);
        else if(op==3) T.rank(x);
        else if(op==4) printf("%d\n",T.t[T.kth(T.root,x)].val);
        else if(op==5) T.pre(x);
        else if(op==6) T.nxt(x);
    }
    return 0;
}