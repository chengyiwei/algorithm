#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int N,M;
int vis[maxn];
string s[maxn];
int max_len;
const int TT1=1e7+9,h1=29;
bool hsh1[TT1];
int id[TT1];
int get1(string x){
	int len=x.size(),now=0;
	for(int i=0;i<len;i++)
		now=(now*h1+(x[i]-'a'+1))%TT1;
	return now;
}
bool cmp(string A,string B){
	return A.size()>B.size();
}

int dfs(int pos){
    int s_sum[355];
	if(vis[pos]==1) return 1;
	if(vis[pos]==-1) return 0;
	int len=s[pos].size();
	s_sum[0]=s[pos][0]-'a'+1;
	for(int i=1;i<len;i++)
		s_sum[i]=(s_sum[i-1]*h1+(s[pos][i]-'a'+1))%TT1;
	int flg=1;
	for(int L=0;L<len;L++)
	for(int R=L;R<len;R++){
		if(L==0&&R==len-1) continue;
		int now_hsh=(s_sum[R]-(L==0?0:s_sum[L-1])+TT1)%TT1;
		if(id[now_hsh]==0) {
			flg=0;
		}
		else flg&=dfs(id[now_hsh]);
		if(flg==0){
			vis[pos]=-1;
			return 0;
		}
	}
	vis[pos]=1;
	return 1;
}
bool cmp2(int a,int b){
	return s[a].size()>s[b].size();
}
int main(){
	freopen("G.in","r",stdin);
	cin>>N;
	max_len=sqrt(N*2)+2;
	for(int i=1;i<=N;i++){
		string now;
		cin>>now;
		if(now.size()>max_len) continue;
		int now_hsh1=get1(now);
		if(hsh1[now_hsh1]) continue;
		hsh1[now_hsh1]++;
		s[++M]=now;
	}
	sort(s+1,s+1+M,cmp);
	for(int i=1;i<=M;i++){
		int now_hsh=get1(s[i]);
		id[now_hsh]=i;
	}
	for(int i=1;i<=M;i++){
		if(vis[i]==0)
			dfs(i);
	}
	for(int i=1;i<=M;i++){
		if(vis[i]==1) {
			cout<<s[i].size()<<endl;
			return 0;
		}
	}
	return 0;
}