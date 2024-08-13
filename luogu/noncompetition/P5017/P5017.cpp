#include<bits/stdc++.h>
using namespace std;
const int maxn=4e6+105,INF=1<<30;
int N,M,max_T,G[maxn],S[maxn],F[maxn],hed=1,til=0,Q[maxn],ans=INF;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline int X(int j){return G[j];}
inline int Y(int j){return F[j]+S[j];}
inline long double calc(int i,int j){return X(i)==X(j)?(Y(j)>Y(i)?INF:-INF):((long double)(Y(i)-Y(j))/(X(i)-X(j)));}
int main(){
    freopen ("P5017.in", "r", stdin);
    freopen ("P5017.out", "w", stdout);
	N=read();M=read();
	for(int i=1;i<=N;i++){
		int now_T=read();
		G[now_T]++;S[now_T]+=now_T;max_T=max(max_T,now_T);
	}
	for(int i=1;i<M+max_T;i++)G[i]+=G[i-1],S[i]+=S[i-1];
	for(int i=0;i<M;i++)F[i]=G[i]*i-S[i];
	Q[++til]=0;
	for(int i=M;i<max_T+M;i++){
		while(hed<til&&calc(Q[hed],Q[hed+1])<=i)++hed;
		int j=Q[hed];
		F[i]=F[j]+(G[i]-G[j])*i-(S[i]-S[j]);
		while(hed<til&&calc(Q[til-1],Q[til])>=calc(Q[til-1],i-M+1))--til;
		Q[++til]=i-M+1;
	}
	for(int i=max_T;i<max_T+M;i++)ans=min(ans,F[i]);
	printf("%d\n",ans);
	return 0;
}