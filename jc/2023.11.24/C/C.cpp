#include<bits/stdc++.h>
using namespace std;
const int maxn=555;
typedef long long LL;
LL F[maxn][maxn];
int main(){
	freopen("C.in","r",stdin);
	int N;
	cin>>N;
//	for(int i=1;i<=N;i++) F[i][i]=1;
	for(int i=1;i<=N;i++){
		F[i][i]=1; 
		for(int j=1;j<i;j++){
			for(int k=j-1;k>0;k--){
				F[i][j]+=F[i-j][k];
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=N;i++){
		ans+=F[N][i];
	}
	printf("%lld\n",ans-1);
	return 0;
}
