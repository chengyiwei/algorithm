#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e4+5;
int N,id[maxn];
LL a[maxn],s[maxn],b[maxn],len;
// b 为整块的操作
void add(int l,int r,LL x){
    if(id[l]==id[r]){
        for(int i=l;i<=r;i++) a[i] += x,s[id[l]]+=x;
        return ;
    }
    for(int i=l;id[i]==id[l];i++) a[i]+=x,s[id[l]]+=x; 
    for(int i=id[l]+1;i<id[r];i++)b[i]+=x,s[i]+=len*x;
    for(int i=r;id[i]==id[r];i--) a[i]+=x,s[id[r]]+=x;
}

LL query(int l,int r,LL TT){
    LL ret=0;
    if(id[l]==id[r]) {
        for(int i=l;i<=r;i++) ret=(ret+a[i]+b[id[l]])%TT;
        return ret;
    }
    for(int i=l;id[i]==id[l];i++) ret=(ret+a[i]+b[id[l]])%TT; // 单点的操作+整块的操作
    for(int i=id[l]+1;i<id[r];i++) ret=(ret+s[i])%TT; // 整块的累加
    for(int i=r;id[i]==id[r];i--) ret=(ret+a[i]+b[id[r]])%TT; 
    return ret;
}
int main(){
    freopen("6280.in","r",stdin);
    cin>>N;
    len=sqrt(N);// 块的大小
    for(int i=1;i<=N;i++) {
        cin>>a[i];
        id[i] =(i-1)/len+1; // id 为每个数属于哪个块
        s[id[i]]+=a[i];
    }
    for(int i=1;i<=N;i++){
        int op,l,r,c;
        cin>>op>>l>>r>>c;
        if(op==0)
            add(l,r,c);
        else 
            cout<< query(l,r,c+1) << endl;
    }
    return 0;
}