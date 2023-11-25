#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+5;
int a[maxn],N;
LL ans=0;
int main(){
    freopen("B.in","r",stdin);
    cin>>N;
    int now=0;
    for(int i=1;i<=N;i++){
    	char ch;
        cin>>ch;
        a[i+2]=ch-'0';
    }
    for(int i=1;i<=N;i++){
        if(a[i+2]||a[i+1]||a[i])
            ans++;
    }
    printf("%lld\n",ans);
    return 0;
}
