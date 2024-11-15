#include<bits/stdc++.h>
#define Gc() getchar()
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define eb emplace_back
#define all(x) x.begin(),x.end()
using namespace std;using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned long long;using pii=pair<int,int>;
const int N=300+5,M=300+5,K=1000+5,mod=1e9+7,Mod=mod-1;const db eps=1e-9;const int INF=1e9+7;mt19937 rnd(28382);
#define Tp template<typename T>
#define Ts template<typename T,typename... Ar>
namespace Debug{
	Tp void _debug(char* f,T t){cerr<<f<<'='<<t<<endl;}
	Ts void _debug(char* f,T x,Ar... y){while(*f!=',') cerr<<*f++;cerr<<'='<<x<<",";_debug(f+1,y...);}
	#ifdef LOCAL
	#define gdb(...) _debug((char*)#__VA_ARGS__,__VA_ARGS__)
	#else 
	#define gdb(...) void()
	#endif
}using namespace Debug;
int n,A[N],e[N][N],m;
int vis[N],mch[N];
int dfs(int x){
	if(vis[x]) return 0;
	vis[x]=1;
	for(int i=1;i<=n;i++) if(e[x][i]){
		if(!mch[i]||dfs(mch[i])) return mch[i]=x,1;
	}
	return 0;
}
void Solve(){
	scanf("%d",&n);
	map<int,vector<int>> f;
	map<int,int> op;
	map<int,int> g;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		vector<int> st;
		int x=A[i];
		for(int i=2;i*i<=x;i++)if(x%i==0){
			st.push_back(i); // st 为 A[i] 的因子
			while(x%i==0) x/=i;
		}
		if(x^1) st.push_back(x);
		auto add=[&](int x){
			if(f.count(x)) return;
			op[x]=0;
			int y=x;
			g[x]=0;
			for(int i:st)if(y%i==0){
				f[x].push_back(i);
				while(y%i==0) y/=i,g[x]++;
			}
		};
		x=A[i];
		for(int i=1;i*i<=x;i++)if(x%i==0){
			add(i);
			add(x/i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=g[A[i]];
	for(int i=0;i<=30;i++){
		for(auto [x,y]:g) if(y==i){
			gdb(x,y);
			for(int j:f[x]) if(op[x/j]){op[x]=1;break;}
			if(op[x]) continue;
			m++;Me(e[m],0);
			for(int j=1;j<=n;j++) if(A[j]%x==0) e[m][j]=1;
			Me(vis,0);
			if(dfs(m)) ans-=y,gdb(x);
			else m--,op[x]=1;
		}
	}
	assert(m==n);
	printf("%lld\n",ans);
}
int main(){
	int t=1;
	// scanf("%d",&t);
	while(t--) Solve();
	cerr<<clock()*1.0/CLOCKS_PER_SEC<<'\n';
}
