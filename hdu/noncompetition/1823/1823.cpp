#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
vector<vector<int> > a;
const int N=200,M=1000;
struct Segment_Tree_2{
    int n;
    vector<int> t;
    Segment_Tree_2(int n){this->n=n;t.assign(n<<2,-1);}
    void push_up(int x){t[x]=max(t[x<<1],t[x<<1|1]);}
    void update(int x,int l,int r,int pos,int val){
        if(l==r) {t[x]=max(t[x],val);return ;}
        int mid=(l+r)>>1;
        if(pos<=mid) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val);
        push_up(x);
    }
    int query(int x,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return t[x];
        int mid=(l+r)>>1;
        int ret=-INF;
        if(ql<=mid) ret=max(ret,query(x<<1,l,mid,ql,qr));
        if(qr>mid) ret=max(ret,query(x<<1|1,mid+1,r,ql,qr));
        return ret;
    }
};

struct Segment_Tree_1{
    int n,m;
    vector<Segment_Tree_2> t;
    Segment_Tree_1(int n,int m){this->n=n;this->m=m;t.assign(n<<2,Segment_Tree_2(m));}
    void update(int x,int l,int r,int pos1,int pos2,int val){
        if(l==r){t[x].update(1,1,m,pos2,val);return ;}
        int mid=(l+r)>>1;
        if(pos1<=mid) update(x<<1,l,mid,pos1,pos2,val);
        else update(x<<1|1,mid+1,r,pos1,pos2,val);
        t[x].update(1,1,m,pos2,val);   //上面的每个结点也要更新
    }
    int query(int x,int l,int r,int ql_1,int qr_1,int ql_2,int qr_2){
        if(ql_1<=l&&r<=qr_1) return t[x].query(1,1,m,ql_2,qr_2);
        int mid=(l+r)>>1;
        int ret=-INF;
        if(ql_1<=mid) ret=max(ret,query(x<<1,l,mid,ql_1,qr_1,ql_2,qr_2));
        if(qr_1>mid) ret=max(ret,query(x<<1|1,mid+1,r,ql_1,qr_1,ql_2,qr_2));
        return ret;
    }
};

int main(){
    // freopen("1823.in","r",stdin);
    int t;
    while(scanf("%d",&t)!=EOF&&t){
        Segment_Tree_1 T(N,M);
        while(t--){
            char op[5];scanf("%s",op);
            if(op[0]=='I'){
                int h;double c,d;scanf("%d%lf%lf",&h,&c,&d);
                T.update(1,1,N,h,c*10,d*10);
            }
            else{
                int xL,xR,yL,yR;double c,d;
                scanf("%d%d%lf%lf",&xL,&xR,&c,&d);yL=c*10;yR=d*10;
                if(xL>xR) swap(xL,xR); if(yL>yR) swap(yL,yR);
                int ans=T.query(1,1,N,xL,xR,yL,yR);
                if(ans==-1) printf("-1\n"); else printf("%.1lf\n",ans/10.0);
            }
        }
    }
    return 0;
}