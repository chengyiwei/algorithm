#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long LL;

struct tree{
    int n;
    vector<int> c;
    tree(int n){this->n=n;c.assign(n+1,0);}
    void add_x(int x,int val){
        for(;x<=n;x+=x&-x)c[x]+=val;
    }
    int get(int x){
        int ret=0;
        for(;x;x-=x&-x)ret+=c[x];
        return ret;
    }
};

signed main(){
    // freopen("P3372.in","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    tree t1(n),t2(n);
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int d=a[i]-a[i-1];
        t1.add_x(i,d);
        t2.add_x(i,(i-1)*d);
    }
    while(m--){
        int op;cin>>op;
        if(op==1){
            int L,R,d;cin>>L>>R>>d;
            t1.add_x(L,d);t1.add_x(R+1,-d);
            t2.add_x(L,(L-1)*d);t2.add_x(R+1,-(R+1-1)*d);
        }
        else{
            int L,R;cin>>L>>R;
            cout<<R*t1.get(R)-t2.get(R)-((L-1)*t1.get(L-1)-t2.get(L-1))<<'\n';
        }
    }
    return 0;
}