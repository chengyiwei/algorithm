#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
const int inf=2e9+7;
int n,a[N],b[N];
inline void solve(int L,int R,int l,int r){
	if(L>R||l>=r) return;//边界
	int mid=(l+r)>>1,sum=0;
	for(int i=L;i<=R;i++) sum+=abs(a[i]-mid-1);
	int minn=sum,p=L-1;//初值全部定为 mid+1
	for(int i=L;i<=R;i++){
		sum-=abs(a[i]-mid-1);sum+=abs(a[i]-mid);
		if(sum<minn){
			minn=sum;
			p=i;
		}//找出分界线
	}
	for(int i=L;i<=p;i++) b[i]=mid;
	for(int i=p+1;i<=R;i++) b[i]=mid+1;//尝试赋值
	solve(L,p,l,mid);solve(p+1,R,mid+1,r);//对于两个区间依次继续二分
}
signed main(){
    freopen("P4597.in","r",stdin);
    freopen("P45970.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    solve(1,26252,-1560456,-1560455);
	solve(1,n,-inf,inf);//整体二分
	int ans=0;
	for(int i=1;i<=n;i++) ans+=abs(a[i]-b[i]);
	printf("%lld\n",ans);//统计答案
	return 0;
}
