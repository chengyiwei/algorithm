#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,t[500100],p2[501000];
vector<int>g[500100];
#define pb push_back
int b[30],o;
void ins(int x){
	for(int i=19;i>=0;i--)if((x>>i)&1){
		if(b[i])x^=b[i];
		else {b[i]=x;return;}
	}
	o++;
}
bool ck(int x){
	for(int i=19;i>=0;i--)if((x>>i)&1){
		if(!b[i])return 0;
		x^=b[i];
	}
	return 1;
}
void sol(){
	scanf("%d",&n);p2[0]=1;for(int i=0;i<=n*2;i++)t[i]=0,g[i].clear(); 
	for(int i=1;i<=n;i++)p2[i]=2*p2[i-1]%mod;
	for(int i=1,a;i<=n;i++)scanf("%d",&a),t[a]++;
	for(int i=1;i<=n;i++)for(int j=0;j<=n*2;j+=i)g[j].pb(i);
	int ans=0;
	for(int i=0;i<=n*2;i++){
		memset(b,0,sizeof(b));
		o=0;
        for(int d:g[i])if(t[d]) {
            o += t[d] - 1;
            ins(d);
        }
		if(ck(i))(ans+=p2[o])%=mod;
        printf("%d %d\n",i, ans);
	}
	printf("%d\n",ans-1);
}

int main(){
    freopen ("C.in", "r", stdin);
	int T;cin>>T;while(T--)sol();
	return 0;
}