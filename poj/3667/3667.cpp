#include<cstdio>
#include<vector>
using namespace std;

struct Seg_Tree{
    int n;
    vector<int> pre,suf,sum,tag;   //1 表示空房间 0 表示有人的房间

    Seg_Tree(int n){this->n=n;pre.assign(n<<2,0);suf.assign(n<<2,0);sum.assign(n<<2,0);tag.assign(n<<2,-1);}

    void push_up(int x,int len){
        pre[x]=pre[x<<1];
        if(pre[x<<1]==len-(len>>1)) pre[x]+=pre[x<<1|1];
        suf[x]=suf[x<<1|1];
        if(suf[x<<1|1]==(len>>1)) suf[x]+=suf[x<<1];
        sum[x]=max(max(sum[x<<1],sum[x<<1|1]),suf[x<<1]+pre[x<<1|1]);
    }

    void build(int x,int l,int r){
        if(l==r){sum[x]=pre[x]=suf[x]=1;return ;}  
        int mid=(l+r)>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x,r-l+1);
    }

    void add_tag(int x,int len,int val){
        if(val==1){sum[x]=pre[x]=suf[x]=len;}
        if(val==0){sum[x]=pre[x]=suf[x]=0;}
        tag[x]=val;
    }

    void push_down(int x,int len){
        if(tag[x]!=-1){
            add_tag(x<<1,len-(len>>1),tag[x]);
            add_tag(x<<1|1,len>>1,tag[x]);
            tag[x]=-1;
        }
    }

    void update(int x,int l,int r,int ql,int qr,int val){ 
        if(ql<=l&&r<=qr){add_tag(x,r-l+1,val);return ;}
        push_down(x,r-l+1);
        int mid=(l+r)>>1;
        if(ql<=mid) update(x<<1,l,mid,ql,qr,val);
        if(qr>mid) update(x<<1|1,mid+1,r,ql,qr,val);
        push_up(x,r-l+1);
    }

    int query(int x,int l,int r,int len){  //在 [1,n] 找到第一个大于等于 len 的位置
        if(l==r) return l;
        push_down(x,r-l+1);
        int mid=(l+r)>>1;
        if(sum[x<<1]>=len) return query(x<<1,l,mid,len);
        if(suf[x<<1]+pre[x<<1|1]>=len) return mid-suf[x<<1]+1;
        return query(x<<1|1,mid+1,r,len);
    }
};

int main(){
//	freopen("3667.in","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    Seg_Tree T(n);

    T.build(1,1,n);
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int val;scanf("%d",&val);
            if(T.sum[1]>=val){
                int pos=T.query(1,1,n,val);
                printf("%d\n",pos);
                T.update(1,1,n,pos,pos+val-1,0);
            }
            else
                printf("0\n");
        }
        else{
            int pos,val;scanf("%d%d",&pos,&val);
            T.update(1,1,n,pos,pos+val-1,1);
        }
    }
    return 0;
}
