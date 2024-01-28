#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;

int read(){
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)){x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

struct node{
    int fa,ch[2],sum,val,lay;
}t[maxn];

bool is_root(int x){ // 判断x是否为根
    int f = t[x].fa;
    return t[f].ch[0] != x && t[f].ch[1] != x;
}

void push_up(int x){
    t[x].sum = t[x].val ^ t[t[x].ch[0]].sum ^ t[t[x].ch[1]].sum;
}

void reverse(int x){
    if(!x) return ;
    swap(t[x].ch[0],t[x].ch[1]);
    t[x].lay ^= 1;
}

void push_down(int x){
    if(t[x].lay){
        reverse(t[x].ch[0]);
        reverse(t[x].ch[1]);
        t[x].lay = 0;
    }
}

void push(int x){ // 递归标记下传
    if(!is_root(x)) push(t[x].fa);
    push_down(x);
}

void rotate(int x){ //旋转
    int f = t[x].fa;
    int g = t[f].fa;
    int k = t[f].ch[1] == x;
    if(!is_root(f)) //如果 f 不是根
        t[g].ch[t[g].ch[1] == f] = x;
    t[x].fa = g;
    
    t[f].ch[k] = t[x].ch[k^1];
    if(t[x].ch[k^1]) t[t[x].ch[k^1]].fa = f;

    t[x].ch[k^1] = f; t[f].fa = x;
    push_up(f); push_up(x);
}

void splay(int x){  //题根，将x旋转到根
    int f,g;
    push(x);
    while(!is_root(x)){
        f = t[x].fa, g = t[f].fa;
        if(!is_root(f))
            (t[f].ch[0] == x) ^ (t[g].ch[0] == f) ? rotate(x) : rotate(f);
        rotate(x);
    }
    push_up(x);
}

void access(int x){  // 在 原树 上建一条实链，起点是根，终点是x
    for(int p = 0; x; p = x, x = t[x].fa){
        splay(x);
        t[x].ch[1] = p;  // 将x的右儿子设置为 p
        push_up(x);
    }
}

void make_root(int x){ // 将 x 在原树上旋转到根的位置
    access(x);  // 建立一条实链
    splay(x);  // 把 x 旋转到当前 splay 树的根
    reverse(x); // 反转
}

void split(int x,int y){ // 把原树上以 x 为起点，以 y 为终点的路径，生成一条实链
    make_root(x); // 将 x 旋转到根
    access(y); // 建立一条实链
    splay(y); // 把 y 旋转到当前 splay 树的根，方便之后的操作
}

void link(int x,int y){ // 在原树上连接 x 和 y
    make_root(x); // 将 x 旋转到根
    t[x].fa = y; // 将 x 的父亲设置为 y
}

void cut(int x,int y){  // 切断 x,y 之间连的边
    split(x,y);
    if(t[y].ch[0] != x || t[x].ch[1]) return ; // 如果 x,y 不直接相连，直接返回
    t[y].ch[0] = t[x].fa = 0; // 切断 x,y 之间的边
    push_up(y); push_up(x);
}

int find_root(int x){ //查找 x 在原树上的根
    access(x); splay(x);
    while(t[x].ch[0]) x = t[x].ch[0];
    return x;
}

int lca(int x,int y){
    access(x);
    int ans;
    for(int p = 0; y; p = y, y = t[y].fa) { //模拟 access
        splay(y);
        t[y].ch[1] = p;
        push_up(y);
        ans = y;  //记录最后一个访问的点
    }
    return ans;
}

int main(){
    freopen("P3379.in","r",stdin);
    int n = read(), m = read(), rt = read();
    for(int i=1;i<n;i++) {
        int x = read(), y = read();
        link(x,y);
    }
    make_root(rt);

    while(m--){
        int x = read(), y = read();
        printf("%d\n",lca(x,y));
    }
    return 0;
}