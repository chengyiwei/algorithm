#include<bits/stdc++.h>
using namespace std;

int n,m;
int block,t;
vector<int> a,belong,st,ed,stp,to;

void update(int x){ //更新第 x 个块
    for(int i=ed[x];i>=st[x];i--){
        if(i+a[i]>ed[x]) 
            to[i]=i+a[i],stp[i]=1;
        else to[i]=to[i+a[i]],stp[i]=stp[i+a[i]]+1;
    }
}

int main(){
    freopen("P3203.in","r",stdin);
    freopen("P3203.out","w",stdout);
    scanf("%d",&n); block=sqrt(n); t=n/block+(n%block!=0);
    a.assign(n+1,0);belong.assign(n+1,0);
    st.assign(t+1,0);ed.assign(t+1,0);stp.assign(n+1,0);to.assign(n+1,0);
    for(int i=1;i<=t;i++) st[i]=(i-1)*block+1,ed[i]=i*block;ed[t]=n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),belong[i]=(i-1)/block+1;
    for(int i=t;i>=1;i--) update(i);
    scanf("%d",&m);
    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int ans=0,x;scanf("%d",&x);x=x+1;
            while(x<=n){
                ans+=stp[x];x=to[x];
            }
            printf("%d\n",ans);
        }
        else{
            int x,val;scanf("%d%d",&x,&val);x=x+1;
            a[x]=val;update(belong[x]);
        }
    }
    return 0;
}