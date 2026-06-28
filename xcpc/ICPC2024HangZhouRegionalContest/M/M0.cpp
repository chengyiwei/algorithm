#include<bits/stdc++.h>
using namespace std;
 
#define vcoistnt ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define int long long
#define vi vector<int>
#define vb vector<bool>
typedef pair<int,int> pll;
 
const int N=2e5+10;
const int inf=1e18;
const int mod=998244353;
 
int n,m;
vi a(N);
vi b(N);
 
//构建笛卡尔树
vi ls(N),rs(N),sta(N);
void build(){
    int top=0;
    for(int i=1;i<=n;i++){
        int pos=top;
        while(pos>0 && b[sta[pos]]>b[i]){
            pos--;
        }
        if(pos>0){
            rs[sta[pos]] = i;
        }
        if(pos<top){
            ls[i]=sta[pos+1];
        }
        sta[++pos] =i;
        top=pos;
    }
}
 
bool dfs(int l,int r,int x,int fa){
    if(fa && b[x]%b[fa]) return 0;
    if(l>=r) return 1;
    return dfs(l,x-1,ls[x],x)&&dfs(x+1,r,rs[x],x);
}
 
bool check(int x){
    
    for(int i=1;i<=n;i++) b[i]=a[i]+x;
    for(int i=1;i<=n;i++) ls[i]=rs[i]=0;    //重置笛卡尔树
    build();
 
    return dfs(1,n,sta[1],0);
    
}
 
void solve(){
 
    cin>>n>>m;
    
    int mn=inf;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mn=min(mn,a[i]);
    }
    
    int g=0;
    for(int i=1;i<n;i++){g=__gcd(g,abs(a[i]-a[i+1]));}  //求最大公约数做差之后即使+x最大公约数也不会受到影响
 
    if(g==0){   //只有一个数以及所有数都相等的情况
        cout<<m<<" "<<m*(m+1)/2<<"\n";return;
    }
 
    vi d;   //统计因子
    
    d.push_back(0);     //我习惯从下标1开始
 
    for(int i=1;i*i<=g;i++){    //求最大公约数的因子
        if(g%i==0){
            d.push_back(i);
            if(i*i!=g) d.push_back(g/i);
        }
    }
    int id=d.size()-1;
 
 
    int cnt=0,sum=0;
    for(int t=1;t<=id;t++){     //检查所有合法的因子
        int x=d[t]-mn;
        if(x<1 || x>m) continue;
        int ret=check(x);
        if(ret) cnt++,sum+=x;
    }
 
    cout<<cnt<<" "<<sum<<"\n";
 
}
signed main() {
    // freopen ("M.in","r",stdin);
    // freopen ("M0.out","w",stdout);
    vcoistnt
    cout<<fixed<<setprecision(2);
    int _=1;
    cin>>_;
    while(_--) solve();
    return 0;
}