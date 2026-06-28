#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    vector<int> a(6);
    for(int i=1;i<=5;i++) cin>>a[i];

    int res=0;
    for(int i=1;i<=2;i++){
        int mi=min(a[i],a[6-i]);
        res+=mi;
        a[i]-=mi,a[6-i]-=mi;
    }
    res+=a[3]/2;
    a[3]%=2;

    auto check=[&](int mid,int i)->bool{
        int s=0;
        for(int j=1;j<i;j++) s+=a[j];
        s+=a[i]-mid;

        return s/(6-i)>=mid;
    };

    for(int i=5;i>=4;i--){
        int l=0,r=a[i];
        while(l<r){
            int mid=(l+r+1)>>1;
            if(check(mid,i)) l=mid;
            else r=mid-1;
        }
        res+=l;
        a[i]-=l;
        int s=l*(6-i);
        for(int j=1;j<=i;j++)
            if(a[j]<=s) s-=a[j],a[j]=0;
            else a[j]-=s,s=0;
    }

    res+=(a[1]+a[2]*2+a[3]*3)/6;

    cout<<res<<endl;
}

signed main(){
    freopen ("B.in", "r", stdin);
    freopen ("B.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int t=1;
    cin>>t;
    while(t--) solve();

    return 0;
}