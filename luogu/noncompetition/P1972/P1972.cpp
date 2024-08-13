#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e6;
struct node{
    int L,R,id;
    node(int L=0,int R=0,int id=0):L(L),R(R),id(id){}
};

int now_ans=0;
vector<int> a,belong,ans,cnt;
vector<node> q;

bool cmp(node a,node b){
    if(belong[a.L]!=belong[b.L]) return belong[a.L]<belong[b.L];
    return a.R<b.R;
}

void add(int x){cnt[a[x]]++;if(cnt[a[x]]==1) now_ans++;}
void del(int x){cnt[a[x]]--;if(cnt[a[x]]==0) now_ans--;}

int main(){
    freopen("P1972.in","r",stdin);
    freopen("P1972.out","w",stdout);
    int n;scanf("%d",&n);
    int block=sqrt(n),t=n/block+(n%block!=0);
    a.assign(n+1,0);belong.assign(n+1,0);ans.assign(n+1,0);cnt.assign(MAXX+1,0); 
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),belong[i]=(i-1)/block+1;
    int m;scanf("%d",&m);q.assign(m+1,node());
    for(int i=1;i<=m;i++){
        int L,R;scanf("%d%d",&L,&R);
        q[i]=node(L,R,i);
    }
    sort(q.begin()+1,q.begin()+1+m,cmp);
    int L=1,R=0;
    for(int i=1;i<=m;i++){
        while(L<q[i].L) del(L++);
        while(R>q[i].R) del(R--);
        while(L>q[i].L) add(--L);
        while(R<q[i].R) add(++R);
        ans[q[i].id]=now_ans;
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}