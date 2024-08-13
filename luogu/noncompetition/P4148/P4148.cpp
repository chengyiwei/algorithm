#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const double alpha = 0.75;

int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Point{
    int dim[2],val;
    Point(){};
    Point(int x,int y,int v):dim{x,y},val(v){}
};

Point order[maxn]; int cnt;

struct node{
    int ls,rs;
    int mi[2],ma[2];
    int sum;
    int siz;
    Point p;
}t[maxn];

int tot,rt;
int top,stk[maxn];

int now;
bool cmp(const Point &a,const Point &b){
    return a.dim[now] < b.dim[now];
}

void update(int u){
    for(int i=0;i<2;i++){
        t[u].mi[i] = t[u].ma[i] = t[u].p.dim[i];
        if(t[u].ls){
            t[u].mi[i] = min(t[u].mi[i],t[t[u].ls].mi[i]);
            t[u].ma[i] = max(t[u].ma[i],t[t[u].ls].ma[i]);
        }
        if(t[u].rs){
            t[u].mi[i] = min(t[u].mi[i],t[t[u].rs].mi[i]);
            t[u].ma[i] = max(t[u].ma[i],t[t[u].rs].ma[i]);
        }
    }
    t[u].sum = t[t[u].ls].sum + t[t[u].rs].sum + t[u].p.val;
    t[u].siz = t[t[u].ls].siz + t[t[u].rs].siz + 1;
}

void slap(int u){
    if(!u) return ;
    slap(t[u].ls);
    order[++cnt] = t[u].p;
    stk[++top] = u; //回收节点
    slap(t[u].rs);
}

int build(int l,int r,int d){
    if(l > r) return 0;
    int u;
    if(top) u = stk[top--];
    else u = ++tot;
    int mid = (l+r)>>1;
    now = d;
    nth_element(order+l,order+mid,order+r+1,cmp);
    t[u].p = order[mid];
    t[u].ls = build(l,mid-1,d^1); t[u].rs = build(mid+1,r,d^1);
    update(u);
    return u;
}

bool not_balance(int u){
    if(t[t[u].ls].siz > t[u].siz*alpha || t[t[u].rs].siz > t[u].siz*alpha) return true;
    return false;
}

void insert(int &u,Point p,int d){
    if(!u){
        if (top) u = stk[top--];
        else u = ++tot;
        t[u].ls = t[u].rs = 0; t[u].p = p;
        update(u);
        return ;
    }
    if(p.dim[d] <= t[u].p.dim[d]) 
        insert(t[u].ls,p,d^1);
    else 
        insert(t[u].rs,p,d^1);
    update(u);
    if(not_balance(u)){
        cnt = 0;
        slap(u);
        u = build(1,cnt,d); //重建
    }
}

int query(int u, int x1, int y1, int x2,int y2){  //询问 x1,y1,x2,y1 这个矩形里面的和
    if(!u) return 0;
    int X1 = t[u].mi[0], Y1 = t[u].mi[1], X2 = t[u].ma[0], Y2 = t[u].ma[1]; //[X1,Y1]为矩形左下角，[X2,Y2]为矩形右上角
    if(x1 <= X1 && X2 <= x2 && y1 <= Y1 && Y2 <= y2) return t[u].sum;  //子树表示的矩形完全在查询矩形内
    if(x1 > X2 || x2 < X1 || y1 > Y2 || y2 < Y1) return 0; //子树表示的矩形完全在查询矩形外
    int ans = 0;
    if(x1 <= t[u].p.dim[0] && t[u].p.dim[0] <= x2 && y1 <= t[u].p.dim[1] && t[u].p.dim[1] <= y2)
         ans += t[u].p.val; //子树的根在查询矩形内
    ans += query(t[u].ls,x1,y1,x2,y2) + query(t[u].rs,x1,y1,x2,y2); //递归查询左右子树
    return ans;
}

int main(){
    freopen("P4148.in","r",stdin);
    int n = read();
    int ans=0;
    while(1){
        int op = read();
        if(op == 1){
            int x = read(), y = read(), val = read();
            x ^= ans; y ^= ans; val ^= ans;
            insert(rt,Point(x,y,val),0);
        }
        if(op == 2){
            int x1 = read(), y1 = read(), x2 = read(), y2 = read();
            x1 ^= ans; y1 ^= ans; x2 ^= ans; y2 ^= ans;
            ans = query(rt,x1,y1,x2,y2);
            printf("%d\n",ans);
        }
        if(op == 3) break;
    }
    return 0;
}