#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
    freopen("K.in","r",stdin);
    freopen("K0.out","w",stdout);
    string s[maxn];
    int N=read(),Q=read();
    for(int i=1;i<=N;i++){
        cin>>s[i];
    }
    for(int i=1;i<=Q;i++){
        string q;
        int ans=0;
        string now_s[maxn];
        cin>>q;
        map<char,char> mp;
        for(int j=0;j<26;j++)
            mp[q[j]]=j+'a';
        for(int j=1;j<=N;j++){
            int siz=s[j].length();
            now_s[j].clear();
        
            for(int k=0;k<siz;k++)
                now_s[j].push_back(mp[s[j][k]]);
        }
        for(int i=1;i<=N;i++)
        for(int j=i+1;j<=N;j++){
            if(now_s[i]>now_s[j]) ans++;
        }
        printf("%d\n",ans);
    }
}