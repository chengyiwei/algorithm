#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int N;
double F[maxn][maxn]; //F[i][k] 表示前 i 个数字，已经选了 k 个最大值
double sumk[maxn],a[maxn];
int main(){
    freopen("E.in","r",stdin);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];
    for(int i=1;i<=N;i++)
    for(int k=1;k<=i;k++){
        F[i][k]=max(F[i-1][k],F[i-1][k-1]*0.9+a[i]);
    }
    double ans=-1000000;
    for(int k=1;k<=N;k++){
        sumk[k]=sumk[k-1]*0.9+1;
        double now=F[N][k]*1.0/sumk[k]-1200.0/sqrt(k);
        ans=max(ans,now);
    }
    printf("%.10lf",ans);
    return 0;
}