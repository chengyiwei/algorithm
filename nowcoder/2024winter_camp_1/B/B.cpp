#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int check(vector<pii>& a){
    sort(a.begin(),a.end());
    if(a.size() == 0) return 2;
    int lst = a[0].first, now = a[0].second;
    for(int i=1;i<a.size();i++){
        if(lst == a[i].first || lst == a[i].first-1){
            if((now ^ a[i].second) == 3) return 0;
            else lst = a[i].first;
        }
        else{
            lst = a[i].first; now = a[i].second;
        }
    }
    return 1;
}

void solve(){
    int n; scanf("%d",&n);
    vector<pii> a,b;
    for(int i=1;i<=n;i++){
        pii x; scanf("%d%d",&x.second,&x.first);
        if(x.first >= 0) a.push_back(x);
        if(x.first <= 0) b.push_back(x);
    }
    int ans1 = check(a) + check(b);
    a.push_back({0,2}); b.push_back({0,2});
    int ans2 = check(a) + check(b) + 1;
    int ans = min(ans1,ans2);
    printf("%d\n",ans);
}

int main(){
    freopen("B.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
}