#include<bits/stdc++.h>
using namespace std;
const int maxn=24;
typedef long long LL;
LL a[maxn],a1;
int p[maxn];
int main(){
    freopen("A.in","r",stdin);
    freopen("A_.out","w",stdout);
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    a1=a[1];
    for(int i=2;i<=N;i++){
        scanf("%d",&p[i]);
    }
    for(int j=1;j<=1000;j++)
        for(int i=2;i<=N;i++)
            a[p[i]]+=a[i];
    for(int i=1;i<=N;i++)
        printf("%d ",a[i]);
    if(a[1]>0) printf("+");
    else if(a[1]<0) printf("-");
    else printf("0");
    return 0;
}   