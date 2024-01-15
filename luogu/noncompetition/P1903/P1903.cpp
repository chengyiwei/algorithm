#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e6;
struct node1{int L,R,t,id,ans;node1(int L=0,int R=0,int t=0,int id=0):L(L),R(R),t(t),id(id){}};
struct node2{int x,val;node2(int x=0,int val=0):x(x),val(val){}};
int now_ans=0;
vector<int> a,belong,cnt;
vector<node1> qQ;
vector<node2> qR;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void print(int x){
    if(x/10) print(x/10);
    putchar(x%10+'0');
}

bool cmp(node1 a,node1 b){  // 先按照 L 排序，再按照 R 排序，最后按照 t 排序
    if(belong[a.L]==belong[b.L]) {
        if(belong[a.R]==belong[b.R]) return a.t<b.t;
        else return belong[a.R]<belong[b.R];
    }
    else return belong[a.L]<belong[b.L];
}

void add(int x){cnt[x]++;if(cnt[x]==1) now_ans++;}
void del(int x){cnt[x]--;if(cnt[x]==0) now_ans--;}

void upd(int i,int t){ // 对时间上的变化所造成变化的维护
    t--;
    if(qR[t].x>=qQ[i].L&&qR[t].x<=qQ[i].R){ //如果这个点在区间内
        del(a[qR[t].x]);add(qR[t].val);
    }
    swap(a[qR[t].x],qR[t].val); // upd 了一次需要交换，因为下一次 upd 就是把这个点变回来
}

int main(){
    freopen("P1903.in","r",stdin);
    freopen("P1903.out","w",stdout);
    int n,m;n=read();m=read();
    int block=pow(n,2/3.0),t=n/block+(n%block!=0);
    a.assign(n+1,0);belong.assign(n+1,0);cnt.assign(MAXX+1,0);
    for(int i=1;i<=n;i++) a[i]=read(),belong[i]=(i-1)/block+1;
    
    for(int i=1;i<=m;i++){
        char op[5];
        scanf("%s",op);
        if(op[0]=='Q'){  // 查询 [l,r] 有多少不同的字母
            int l,r;l=read();r=read();
            qQ.push_back(node1(l,r,qR.size(),i)); // 在这个点之前修改了 qR.size() 次
        }
        else{
            int x,val;x=read();val=read(); //按照修改把长度 m 的询问序列分成几个部分
            qR.push_back(node2(x,val));
        }
    }
    sort(qQ.begin(),qQ.end(),cmp); // 按照块排序
    int L=1,R=0,T=0;
    for(int i=0;i<qQ.size();i++){
        while(L<qQ[i].L) del(a[L++]);
        while(R>qQ[i].R) del(a[R--]);
        while(L>qQ[i].L) add(a[--L]);
        while(R<qQ[i].R) add(a[++R]);
        while(T<qQ[i].t) upd(i,++T);
        while(T>qQ[i].t) upd(i,T--);
        qQ[i].ans=now_ans;
    }
    sort(qQ.begin(),qQ.end(),[](node1 a,node1 b){return a.id<b.id;});
    for(int i=0;i<qQ.size();i++) print(qQ[i].ans),putchar('\n');
    return 0;
}