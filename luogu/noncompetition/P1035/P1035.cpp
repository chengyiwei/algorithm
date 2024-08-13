#include<bits/stdc++.h>
using namespace std;
int k;
double ans;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	k=read();
	for(int i=1;i;i++){
		ans+=1.0/i;
		if(ans>k){printf("%d\n",i);break;}
	}
	return 0;
}