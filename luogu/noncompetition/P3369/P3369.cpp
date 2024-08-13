#include<bits/stdc++.h>
using namespace std;

struct Node{
    int lson,rson;
    int val,siz,tsiz,fa;  //子树大小。正式子树大小
    int real; //真实
    Node(){
        lson=rson=0;
        val=siz=tsiz=fa=0;
        real=1;
    }
};

struct BST{
    vector<Node> t;
    vector<int> order;
    const double aplpha=0.75; //平衡因子
    int root=0,tot=0,rb=0;

    BST(int n){
        t.assign(n+1,Node());
    }

    bool isbad(int u){ //判断平衡
        if((double)t[u].tsiz*aplpha < (double)max(t[t[u].lson].tsiz,t[t[u].rson].tsiz)) return true;
        return false;
    }
    
    void insert(int& u,int val){
        if(!u){
            u=++tot;
            t[u].val=val;
            t[u].siz=t[u].tsiz=t[u].real=1;
            t[u].lson=t[u].rson=0;
            return ;
        }
        t[u].siz++;t[u].tsiz++;
        if(val<=t[u].val) insert(t[u].lson,val);
        else insert(t[u].rson,val);
        if(isbad(u)) rebuild(u);
    }

    int kth(int k){
        for(int u=root;u;){
            if(t[u].real&&t[t[u].lson].tsiz+1==k) 
                return t[u].val;
            if(t[t[u].lson].tsiz>=k) 
                u=t[u].lson;
            else 
                k-=t[t[u].lson].tsiz+t[u].real,
                u=t[u].rson;
        }
        return 0;    
    }

    int rank(int val){ //返回值 val 的排名
        int ans=1;
        for(int u=root;u;){
            if(val<=t[u].val)
                u=t[u].lson;
            else 
                ans+=t[t[u].lson].tsiz+t[u].real,
                u=t[u].rson;
        }
        return ans;
    }

    void pop_rk(int &u,int rk){  //删除排名为 rk 的节点
        if(t[u].real&&t[t[u].lson].tsiz+1==rk){ //找到了
            t[u].real=0;
            t[u].tsiz--;
            return ;
        }
        t[u].tsiz--;
        if(t[t[u].lson].tsiz+t[u].real>=rk) //在左子树
            pop_rk(t[u].lson,rk);
        else 
            pop_rk(t[u].rson,rk-(t[t[u].lson].tsiz+t[u].real));
    }

    void pop(int val){  //删除值为 val 的节点
        pop_rk(root,rank(val)); //先找到排名
        if(1.0*t[root].siz*aplpha > 1.0*t[root].tsiz)  //如果无用节点过多，重建
            rebuild(root);
    }

    void dfs(int u){
        if(!u) return ;
        dfs(t[u].lson);
        if(t[u].real) order.push_back(u);
        dfs(t[u].rson);
    }

    void build(int &u,int l,int r,int fa=0){
        int mid=(l+r)>>1;
        u=order[mid];
        t[u].fa=fa;
        if(l==r){
            t[u].lson=t[u].rson=0;
            t[u].siz=t[u].tsiz=1;
            return ;
        }
        if(l<mid) 
            build(t[u].lson,l,mid-1,u);
        else 
            t[u].lson=0;
        if(r>mid) 
            build(t[u].rson,mid+1,r,u);
        else 
            t[u].rson=0;
        t[u].siz=t[t[u].lson].siz+t[t[u].rson].siz+1;
        t[u].tsiz=t[t[u].lson].tsiz+t[t[u].rson].tsiz+t[u].real;
    }

    void rebuild(int &u){
        order.assign(1,0);
        dfs(u);
        if(order.size()!=1) //没有新的元素
            build(u,1,order.size()-1,t[u].fa);
        else
            u=0;
    }

};

int main(){
    freopen("P3369.in","r",stdin);
    freopen("P3369.out","w",stdout);
    int Q; scanf("%d",&Q);
    BST T(Q);
    int op,x;
    while(Q--){
        scanf("%d%d",&op,&x);
        if(op==1){
            T.insert(T.root,x);
            // if(T.rb) { //重建
            //     if(T.rb==T.root) T.rebuild(T.root);
            //     else if(T.rb==T.t[T.t[T.rb].fa].lson) T.rebuild(T.t[T.t[T.rb].fa].lson);
            //     else T.rebuild(T.t[T.t[T.rb].fa].rson);
            //     T.rb=0;
            // }
        }
        if(op==2){
            T.pop(x);
        }
        if(op==3){
            printf("%d\n",T.rank(x));
        }
        if(op==4){
            printf("%d\n",T.kth(x));
        }
        if(op==5){
            printf("%d\n",T.kth(T.rank(x)-1));
        }
        if(op==6){
            printf("%d\n",T.kth(T.rank(x+1)));
        }
    }
    return 0;
}