#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct Node{
    int fa,ch[2],siz,val;
}t[maxn];

int cnt,rt;

void push_up(int x){
    t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+1;
}

bool ident(int x,int f) {return t[f].ch[1] == x;}

void connect(int x,int f,int s){ //把 x 连接到 f 的 s 侧
    t[f].ch[s]=x;
    t[x].fa=f;
}

void rotate(int x){
    int f = t[x].fa, g = t[f].fa, k = ident(x,f);
    connect(x,g,ident(f,g)); connect(t[x].ch[k^1],f,k);  connect(f,x,k^1);
    push_up(f);push_up(x);
}

void splay(int x,int top){ //代表把x转到top的儿子，top为0则转到根结点
    if(!top) rt=x;
    while(t[x].fa != top){
        int f = t[x].fa, g = t[f].fa;
        if(g != top)
            ident(x,f) ^ ident(f,g) ? rotate(x) : rotate(f);
        rotate(x);
    }
}

void newnode(int &x,int f,int val){
    t[x=++cnt].fa = f; t[x].val=val; t[x].siz=1;
}

void insert(int val, int &x = rt, int fa = 0){
    if(!x)
        newnode(x,fa,val), splay(x,0);
    else if(val < t[x].val)
        insert(val,t[x].ch[0],x);
    else
        insert(val,t[x].ch[1],x);
}

void delnode(int x){
    splay(x,0);
    if(t[x].ch[1]){ //存在右节点
        int p = t[x].ch[1];
        while(t[p].ch[0]) p = t[p].ch[0]; //找到 x 的后继
        splay(p,x);
        connect(t[x].ch[0],p,0);
        rt = p;
        t[p].fa = 0;
        push_up(p);
    }
    else 
        rt = t[x].ch[0], t[rt].fa = 0;
}

void del(int val,int x = rt){
    if(val == t[x].val)
        delnode(x);
    else if(val < t[x].val)
        del(val,t[x].ch[0]);
    else
        del(val,t[x].ch[1]);
}

int get_rank_1(int val, int x = rt){  //会超时
    if(!x) 
        return 0;
    if(val <= t[x].val)
        return get_rank_1(val,t[x].ch[0]);
    else
        return get_rank_1(val,t[x].ch[1]) + t[t[x].ch[0]].siz + 1;
}

int get_rank_2(int val){
    int x = rt, ret = 1, pre = 0;
    while(x){
        if(val <= t[x].val)
            pre = x, x = t[x].ch[0];
        else
            ret += t[t[x].ch[0]].siz + 1, x = t[x].ch[1];
    }
    if(pre)
        splay(pre,0);
    return ret;
}

int kth_1(int k, int x = rt){
    if(k == t[t[x].ch[0]].siz + 1)
        return t[x].val;
    if(k <= t[t[x].ch[0]].siz)
        return kth_1(k, t[x].ch[0]);
    else
        return kth_1(k - t[t[x].ch[0]].siz - 1,t[x].ch[1]);
}

int kth_2(int k){
    int x = rt;
    while(x){
        if(k == t[t[x].ch[0]].siz + 1){
            splay(x,0); break;
        }
        else if(k <= t[t[x].ch[0]].siz)
            x = t[x].ch[0];
        else
            k -= t[t[x].ch[0]].siz + 1, x = t[x].ch[1];
    }
    return t[x].val;
}

int pre(int val, int x = rt){
    if(!x)
        return -INF;
    if(val <= t[x].val)
        return pre(val,t[x].ch[0]);
    else
        return max(t[x].val,pre(val,t[x].ch[1]));
}

int nxt(int val, int x = rt){
    if(!x)
        return INF;
    if(val >= t[x].val)
        return nxt(val,t[x].ch[1]);
    else
        return min(t[x].val,nxt(val,t[x].ch[0]));
}

signed main(){
    freopen("P3369.in","r",stdin);
    int T; cin >> T;
    while(T--){
        int op, x;
        cin >> op >> x;
        if(op == 1)
            insert(x);
        else if(op == 2)
            del(x);
        else if(op == 3)
            printf("%d\n",get_rank_2(x));
        else if(op == 4)
            printf("%d\n",kth_2(x));
        else if(op == 5)
            printf("%d\n",pre(x));
        else
            printf("%d\n",nxt(x));
    }
    return 0;
}