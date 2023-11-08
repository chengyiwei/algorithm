#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int N;
LL a[maxn];
LL ans=0,money;
int main(){
    // freopen("A.in","r",stdin);
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>a[i];
    sort(a+1,a+1+N);
    for(int i=N;i;i--){
        if(a[i]*(N-i+1)>=ans)
            ans=a[i]*(N-i+1),money=a[i];
    }
    cout<<ans<<" "<<money<<endl;
    return 0;
}