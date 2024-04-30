#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    freopen("E.in","r",stdin);
    int n;scanf("%d",&n);
    LL ans=0,cnt=0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    stack<int> st;
    for(int i=1;i<=n;i++){
        st.push(a[i]);cnt+=a[i];
        if(st.size()>=2&&cnt>0){
            ans+=cnt;
            while(!st.empty()) st.pop();
            st.push(cnt);
        }
    }
    printf("%lld\n",ans);
    return 0;
}