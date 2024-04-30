#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int w[maxn],h[maxn];
typedef long long LL;
LL sum=0;
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)scanf("%d",&h[i]);
    for(int i=1;i<=M;i++)scanf("%d",&w[i]);
    sort(h+1,h+1+N);sort(w+1,w+1+M);
    int pos=1;
    for(int i=1;i<=N;i++){
        while(pos<=M&&w[pos]<h[i]) pos++;
        if(pos<=M&&w[pos]>=h[i]){
            sum+=w[pos];pos++;
        }
        else {
            printf("you died!\n");
            return 0;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
