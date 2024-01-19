#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;

int n,m,rt;

int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct Node{
    int siz,fa,ch[2],tag;
}t[maxn];

void push_up(int x){
    t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+1;
}

void push_down(int x){
    if(t[x].tag){
        swap(t[x].ch[0],t[x].ch[1]);
        t[t[x].ch[0]].tag^=1;
        t[t[x].ch[1]].tag^=1;
        t[x].tag=0;
    }
}

void build(int l,int r,int f){ //建立一棵以f为根的[l,r]区间的树
    if(l>r) return ;
    int mid=(l+r)>>1;
    if(mid < f) t[f].ch[0]=mid;
    else t[f].ch[1]=mid;
    t[mid].fa=f;t[mid].siz=1;
    if(l==r) return ;  //到达叶子节点
    build(l,mid-1,mid); build(mid+1,r,mid);
    push_up(mid);
}

void rotate(int x,int &goal){  //把 x 往上转一次
    int f=t[x].fa,g=t[f].fa; //父亲和祖父
    int op=t[f].ch[1]==x; //判断x是f的左儿子还是右儿子
    if(f==goal) goal=x;
    else t[g].ch[t[g].ch[1]==f]=x; //把 x 放到 g 的儿子位置，并且与 f 同侧
    
    t[t[x].ch[op^1]].fa=f; t[f].fa=x; t[x].fa=g; // 把 f 放在 x 的儿子位置，并且与 x 原来相对于 f 的反侧，那么原来这个位置 x 的儿子要交给 f，称为 f 的儿子
    t[f].ch[op]=t[x].ch[op^1]; t[x].ch[op^1]=f; // 处理 x 原来的另外一个儿子，把它放在 f 的儿子位置
    push_up(f);push_up(x);
}

void splay(int x,int &goal){
    while(x!=goal){  //goal 会改变，但 x 不会改变
        int f=t[x].fa,g=t[f].fa;
        if(f!=goal){
            if((t[f].ch[1]==x)^(t[g].ch[1]==f)) rotate(x,goal); //在不同侧，先旋转 x
            else rotate(f,goal); //在同侧，先旋转 f
        }
        rotate(x,goal);
    }
}

void splay(int x,int top){
    if(!top) root=x;
    while(t[x].fa!=top){
        int f=t[x].fa,g=t[f].fa;
        if(g!=top){
            if(ident(x,f)^ident(f,g)) rotate(x);
            else rotate(f);
        }
        rotate(x);
    }
}

void rever(int L,int R){
    splay(L,rt); splay(R,t[L].ch[1]);
    t[t[R].ch[0]].tag^=1;
}

int find(int x,int k){  //找到以 x 为根的树中第 k 个节点
    push_down(x);
    int sum=t[t[x].ch[0]].siz+1;
    if(sum==k) return x;
    if(sum > k) return find(t[x].ch[0],k);  //在左子树中
    else return find(t[x].ch[1],k-sum); //在右子树中
}

void inorder(int x){
    push_down(x);
    if(t[x].ch[0]) inorder(t[x].ch[0]);
    if(x>=2&&x<=n+1) printf("%d ",x-1);
    if(t[x].ch[1]) inorder(t[x].ch[1]);
}
int main(){
    freopen("P3391.in","r",stdin);
    freopen("P3391_0.out","w",stdout);
    n=read();m=read();
    rt=(n+3)/2; build(1,n+2,rt);
    while(m--){
        int l=read(),r=read();
        int L=find(rt,l),R=find(rt,r+2);
        rever(L,R);
    }
    inorder(rt);
    return 0;
}