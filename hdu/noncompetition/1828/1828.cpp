#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int INF=0x3f3f3f3f;

struct Line{
    int y;
    int left_x,right_x,op;
    Line(int y=0,int left_x=0,int right_x=0,int op=0):y(y),left_x(left_x),right_x(right_x),op(op){};
};

struct Segment_Tree{
    int n;
    vector<int> sum,num,len,left_flag,right_flag;
    Segment_Tree(int n){this->n=n;sum.assign(n<<2,0);num.assign(n<<2,0);len.assign(n<<2,0);left_flag.assign(n<<2,0);right_flag.assign(n<<2,0);}
    void push_up(int x,int l,int r){
        if(sum[x]){num[x]=1;len[x]=r-l+1;left_flag[x]=right_flag[x]=1;}
        else if(l==r){num[x]=len[x]=left_flag[x]=right_flag[x]=0;}
        else{
            num[x]=num[x<<1]+num[x<<1|1];
            if(right_flag[x<<1]&&left_flag[x<<1|1])num[x]--;
            len[x]=len[x<<1]+len[x<<1|1];
            left_flag[x]=left_flag[x<<1];
            right_flag[x]=right_flag[x<<1|1];
        }
    }

    void update(int x,int l,int r,int ql,int qr,int val){
        if(ql<=l&&r<=qr){sum[x]+=val;push_up(x,l,r);return;}
        int mid=(l+r)>>1;
        if(ql<=mid)update(x<<1,l,mid,ql,qr,val);
        if(qr>mid)update(x<<1|1,mid+1,r,ql,qr,val);
        push_up(x,l,r);
    }
};

int main(){
    freopen("1828.in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF){
        int max_x=-INF,min_x=INF;
        vector<Line> lines(2*n+1);

        for(int i=1;i<=n;i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            max_x=max(max_x,max(x1,x2));
            min_x=min(min_x,min(x1,x2));
            lines[i*2-1]=Line(y1,x1,x2,1);
            lines[i*2]=Line(y2,x1,x2,-1);
        }
        for(int i=1;i<=2*n;i++){
            lines[i].left_x=lines[i].left_x-min_x+1;
            lines[i].right_x=lines[i].right_x-min_x+1;
        }
        max_x=max_x-min_x+1;
        Segment_Tree T(max_x);
        sort(lines.begin()+1,lines.begin()+1+2*n,[](const Line &a,const Line &b){return a.y<b.y||(a.y==b.y&&a.op>b.op);});
        int lst=0; LL ans=0;
        for(int i=1;i<=2*n;i++){
            if(lines[i].left_x<lines[i].right_x)
                T.update(1,1,max_x,lines[i].left_x,lines[i].right_x-1,lines[i].op);
            if(i!=2*n&&lines[i].y==lines[i+1].y&&lines[i].op==lines[i+1].op) continue;
            ans+=abs(T.len[1]-lst);lst=T.len[1];
            if(i!=2*n) ans+=T.num[1]*2*(lines[i+1].y-lines[i].y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}