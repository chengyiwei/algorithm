#include<bits/stdc++.h>
using namespace std;

vector<int> a,belong,add;
vector<vector<int> > b;
int block,num;

void reset(int p){ //重新计算
    int st=(p-1)*block+1,ed=p*block;b[p].clear();
    for(int i=st;i<=ed;i++) b[p].push_back(a[i]);
    sort(b[p].begin(),b[p].end());
}

int find(int pid,int val){ //有多少个 小于 val 的，那么就有 block - val 个大于等于 val
    return lower_bound(b[pid].begin(),b[pid].end(),val-add[pid])-b[pid].begin();
}

int query(int ql,int qr,int val){// [ql,qr] 有多少个比 val 大的 
    int ret=0;  
    if(belong[ql]==belong[qr]){
        for(int i=ql;i<=qr;i++) if(a[i]+add[belong[ql]]>=val) ret++;
        return ret;
    }
    for(int i=ql;belong[i]==belong[ql];i++) if(a[i]+add[belong[ql]]>=val) ret++;
    for(int i=belong[ql]+1;i<=belong[qr]-1;i++) ret+=block-find(i,val);
    for(int i=qr;belong[i]==belong[qr];i--) if(a[i]+add[belong[qr]]>=val) ret++;
    return ret;
}

void update(int ql,int qr,int val){
    if(belong[ql]==belong[qr]){ //在一个块中
        for(int i=ql;i<=qr;i++) a[i]+=val;
        reset(belong[ql]); return ;
    }
    for(int i=ql;belong[i]==belong[ql];i++) a[i]+=val; reset(belong[ql]);
    for(int i=belong[ql]+1;i<=belong[qr]-1;i++) add[i]+=val;
    for(int i=qr;belong[i]==belong[qr];i--) a[i]+=val; reset(belong[qr]);
}

int main(){
    freopen("P2801.in","r",stdin);
    int n,q;scanf("%d%d",&n,&q); block=sqrt(n),num=n/block+(n%block!=0);
    a.assign(n+1,0);belong.assign(n+1,0); b.assign(num+1,vector<int>()); add.assign(num+1,0);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) belong[i]=(i-1)/block+1,b[belong[i]].push_back(a[i]);  // b 为 a 的副本
    for(int i=1;i<=num;i++) sort(b[i].begin(),b[i].end());
    while(q--){
        char op[5];scanf("%s",op);
        if(op[0]=='M'){
            int ql,qr,val;scanf("%d%d%d",&ql,&qr,&val);
            update(ql,qr,val);
        }
        if(op[0]=='A'){
            int ql,qr,val;scanf("%d%d%d",&ql,&qr,&val);
            printf("%d\n",query(ql,qr,val));
        }
    }
    return 0;
}