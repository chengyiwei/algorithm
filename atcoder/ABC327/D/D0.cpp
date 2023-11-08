#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int N,M,a[maxn],b[maxn];
int fa[maxn<<1];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
    int fx=getfa(x),fy=getfa(y);
    if(fx!=fy) fa[fx]=fy;
}
int main(){
    freopen("D.in","r",stdin);
    cin>>N>>M;
    for(int i=1;i<=(N<<1);i++) fa[i]=i;
    for(int i=1;i<=M;i++) cin>>a[i];
    for(int i=1;i<=M;i++) cin>>b[i];
    for(int i=1;i<=M;i++){
        int fx=getfa(a[i]),fy=getfa(b[i]);
        if(fx==fy) {printf("No\n");return 0;}
        merge(a[i],b[i]+N);
        merge(b[i],a[i]+N);
    }
    printf("Yes\n");
    return 0;
}