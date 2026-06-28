#include<bits/stdc++.h>
using namespace std;

struct Seg_Tree{
    int n;
    vector<int> t,tag; // t 表示这个区间内花瓶的插了几个了，如果 tag=1 就表示已经插满了花了，tag=0 表示全部清零

    Seg_Tree(int n){this->n=n;t.assign(n<<2,0);tag.assign(n<<2,-1);}

    void push_up(int x){t[x]=t[x<<1]+t[x<<1|1];}

    void add_tag(int x,int l,int r,int val){
        if(val==0)
            t[x]=0,tag[x]=0;
        if(val==1)
            t[x]=(r-l+1),tag[x]=1;
    }

    void push_down(int x,int l,int r){
        if(tag[x]!=-1){
            int mid=(l+r)>>1;
            add_tag(x<<1,l,mid,tag[x]);
            add_tag(x<<1|1,mid+1,r,tag[x]);
            tag[x]=-1;
        }
    }

    void update(int x,int l,int r,int ql,int qr,int val){ //给 ql-qr 全部赋值为 val
        if(ql<=l&&r<=qr){add_tag(x,l,r,val);return ;}
        push_down(x,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid) update(x<<1,l,mid,ql,qr,val);
        if(qr>mid)  update(x<<1|1,mid+1,r,ql,qr,val);
        push_up(x);
    }

    int query(int x,int l,int r,int ql,int qr){  //询问 ql-qr 一共有多少个 1
        if(ql<=l&&r<=qr) return t[x];
        push_down(x,l,r);
        int mid=(l+r)>>1,ret=0;
        if(ql<=mid) ret+=query(x<<1,l,mid,ql,qr);
        if(qr>mid)  ret+=query(x<<1|1,mid+1,r,ql,qr);
        return ret;
    }

    int find(int x,int l,int r,int ql,int qr,int k) {  //寻找 ql-qr 第 k 个 0 的位置
        if(l==r) return l;
        push_down(x,l,r);
        int mid=(l+r)>>1;
        
        if(ql>mid) return find(x<<1|1,mid+1,r,ql,qr,k); //如果查询区间不包括左区间，之间查询右区间

        int left_sum=query(x<<1,l,mid,ql,mid);   // 左区间 1 的个数
        if(k <= mid-ql+1-left_sum)   
            return find(x<<1,l,mid,ql,mid,k);  // 在左边
        else 
            return find(x<<1|1,mid+1,r,mid+1,qr,k-(mid-ql+1-left_sum)); //在右边
    }
};

void solve(){
    int n,m;scanf("%d%d",&n,&m);
    Seg_Tree T(n);

    while(m--){
        int op,A,B;scanf("%d%d%d",&op,&A,&B);
        if(op==1){
            A++;
            int tmp_sum=T.query(1,1,n,A,n);
            if(tmp_sum==(n-A+1)) {printf("Can not put any one.\n");continue;}
            if((n-A+1)-tmp_sum < B) B=(n-A+1)-tmp_sum;
            int pos1=T.find(1,1,n,A,n,1);
            int pos2=T.find(1,1,n,pos1,n,B);
            if(pos2==-1) pos2=n;
            printf("%d %d\n",pos1-1,pos2-1);
            T.update(1,1,n,pos1,pos2,1);
        }
        else{
            A++;B++;
            printf("%d\n",T.query(1,1,n,A,B));
            T.update(1,1,n,A,B,0);
        }
    }
    printf("\n");
}

int main(){
    // freopen("4614.in","r",stdin);
    // freopen("46140.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--) solve();
    return 0;
}