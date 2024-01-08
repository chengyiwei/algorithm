#include<bits/stdc++.h>
using namespace std;

struct Scan_Line{
    double y; /// 边 y 的坐标
    double left_x,right_x; // 边的右端点和左端点
    int op; // 1 表示入边 -1 表示出边
    Scan_Line(double y=0,double left_x=0,double right_x=0,int op=0):y(y),left_x(left_x),right_x(right_x),op(op){}
};


vector<double> xx;

bool cmp(Scan_Line a,Scan_Line b){return a.y<b.y;} //按照 y 坐标从小到大排序

struct Segment_Tree{
    int n;
    vector<double> t;
    vector<int> sum; 
    Segment_Tree(int n){this->n=n;t.assign(n<<2,0);sum.assign(n<<2,0);}
    void push_up(int x,int l,int r){
        if(sum[x]) t[x]=xx[r+1]-xx[l];
        else if(l==r) t[x]=0;
        else t[x]=t[x<<1]+t[x<<1|1];
    }
    void update(int x,int l,int r,int ql,int qr,int val){
        if(ql<=l&&r<=qr){sum[x]+=val;push_up(x,l,r);return ;}
        int mid=(l+r)>>1;
        if(ql<=mid) update(x<<1,l,mid,ql,qr,val);
        if(qr>mid) update(x<<1|1,mid+1,r,ql,qr,val);
        push_up(x,l,r);
    }
};


int main(){
    freopen("1542.in","r",stdin);
    freopen("1542.out","w",stdout);
    int n,cas=0;
    while(scanf("%d",&n),n){
        int cnt=0;
        vector<Scan_Line> lines(2*n+1);
        xx.assign(2*n+1,0);
        for(int i=1;i<=n;i++){
            double x1,x2,y1,y2;scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            lines[++cnt]=Scan_Line(y1,x1,x2,1);
            lines[++cnt]=Scan_Line(y2,x1,x2,-1);
            xx[cnt-1]=x1;xx[cnt]=x2;
        }
        sort(xx.begin()+1,xx.begin()+cnt+1); 
        int num=unique(xx.begin()+1,xx.begin()+cnt+1)-(xx.begin()+1);//去重,离散化
        Segment_Tree T(num);
        sort(lines.begin()+1,lines.begin()+cnt+1,cmp);
        double ans=0;
        for(int i=1;i<=cnt;i++){
            int L,R;
            ans+=T.t[1]*(lines[i].y-lines[i-1].y);
            L=lower_bound(xx.begin()+1,xx.begin()+num+1,lines[i].left_x)-xx.begin();
            R=lower_bound(xx.begin()+1,xx.begin()+num+1,lines[i].right_x)-xx.begin();
            T.update(1,1,num,L,R-1,lines[i].op);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++cas,ans);
    }
    return 0;
}