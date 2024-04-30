#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

int n,C;

bool check(int L,vector<vector<int> >& p){
    vector<int> F(C+10,0);
    F[0]=1;    
    for(int i=1;i<=L;i++){
        for(int j=0;j<p[i].size();j++){
            for(int k=C;k>=p[i][j]*i;k--)
                F[k]=F[k]+F[k-p[i][j]*i];
        }
    }

    if(F[C]>0) return 1;

    for(int i=1;i<=C;i++){
        for(int j=0;j<p[i].size();j++)
            for(int k=p[i][j]*i;k<=C;k++)
                F[k]=F[k]-F[k-p[i][j]*i];

        int i_=i+L;
        if(i_>C) break;

        for(int j=0;j<p[i_].size();j++)
            for(int k=C;k>=p[i_][j]*i_;k--)
                F[k]=F[k]+F[k-p[i_][j]*i_];

        if(F[C]>0) return 1;
    }

    return 0;
}

void solve(){
    n=read(),C=read();
    vector<int> a(C+1,0);
    vector<vector<int> > p(C+1,vector<int>());
    for(int i=1;i<=n;i++){
        int x=read();
        a[x]++;
    }
    if(a[C]>0) {printf("0\n");return ;}
    for(int i=1;i<=C;i++){
        int x=a[i];
        for(int j=1;j<=x;j*=2){
            p[i].push_back(j);
            x-=j;
        }
        if(x) p[i].push_back(x);
    }
    int L=1,R=C,ans=INF,mid;
    while(L<=R){
        mid=(L+R)/2;
        if(check(mid,p)) {ans=min(ans,mid);R=mid-1;}
        else L=mid+1;
    }
    if(ans==INF) printf("-1\n");
    else printf("%d\n",ans-1);
}

int main(){
    freopen("D.in","r",stdin);
    freopen("D0.out","w",stdout);
    int T=read();
    while(T--) solve();
}