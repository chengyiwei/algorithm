#include<bits/stdc++.h>
using namespace std;

struct Seg_Tree{
    int n;
    vector<int> t,pre,suf; 

    Seg_Tree(int n){this->n=n;t.assign(n<<2,0);pre.assign(n<<2,0);suf.assign(n<<2,0);}

    void push_up(int x,int len){
        pre[x]=pre[x<<1];
        suf[x]=suf[x<<1|1];
        if(pre[x]==len-(len>>1)) pre[x]+=pre[x<<1|1];  //如果左儿子全是 1，那么左边的pre就是左儿子的个数加上右儿子的pre
        if(suf[x]==(len>>1)) suf[x]+=suf[x<<1];  //如果右儿子全是 1，那么右边的suf就是右儿子的个数加上左儿子的suf
    }

    void build(int x,int l,int r){
        if(l==r){t[x]=pre[x]=suf[x]=1;return ;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x,r-l+1);
    }

    void update(int x,int l,int r,int pos,int val){ 
        if(l==r) {t[x]=pre[x]=suf[x]=val;return ;}
        int mid=(l+r)>>1;
        if(pos<=mid) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val);
        push_up(x,r-l+1);
    }

    int query(int x,int l,int r,int pos){
        if(l==r) return t[x];
        int mid=(l+r)>>1;
        if(pos<=mid){
            if(pos+suf[x<<1]>mid) return suf[x<<1]+pre[x<<1|1];
            else return query(x<<1,l,mid,pos);
        }
        else{
            if(mid+pre[x<<1|1]>=pos) return suf[x<<1]+pre[x<<1|1];
            else return query(x<<1|1,mid+1,r,pos);
        }
    }
};

int main(){
    // freopen("1540.in","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        Seg_Tree T(n); stack<int> st;
        T.build(1,1,n);
        while(m--){
            char op[10];scanf("%s",op);
            if(op[0]=='Q'){
                int x;scanf("%d",&x);
                printf("%d\n",T.query(1,1,n,x)); //询问 x 有多少 1 是和他连的
            }
            if(op[0]=='D'){
                int x;scanf("%d",&x);
                st.push(x);
                T.update(1,1,n,x,0); //摧毁 x 村庄
            }
            if(op[0]=='R'){
                int x=st.top();st.pop();
                T.update(1,1,n,x,1); //重建 x 村庄
            }
        }
    }
    return 0;
}