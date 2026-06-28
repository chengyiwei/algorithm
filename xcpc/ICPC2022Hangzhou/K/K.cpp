#include<bits/stdc++.h>
using namespace std;
int N,Q;
typedef long long LL;
const int maxn=5e5+5,maxL=1e6+5;
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t[maxL][26],Len=0;
LL num[maxL],now_ans=0,ans2;
string s[maxn];
LL ans[26][26];


void in(string s){
    int siz=s.length(),pos=0;

    for(int i=0;i<siz;i++){
        int now_x=s[i]-'a';
        for(int j=0;j<26;j++){
            if(now_x==j) continue;
            ans[j][now_x]+=num[t[pos][j]];
        }

        if(t[pos][now_x]==0) {
            ++Len;
            t[pos][now_x]=Len;
            pos=Len;
        }

        else {
            pos=t[pos][now_x];
            if(i==siz-1){
                for(int j=0;j<26;j++)
                    ans2+=num[t[pos][j]];
            }
        }
        num[pos]++;
    }
}

int main(){
    freopen("K.in","r",stdin);
    freopen("K.out","w",stdout);
    N=read(),Q=read();
    for(int i=1;i<=N;i++){
        cin>>s[i];
        in(s[i]);
    }
    for(int i=1;i<=Q;i++){
        now_ans=0;
        string q;cin>>q;
        int siz=q.length();
        vector<int> id(26);
        for(int j=0;j<siz;j++){
            id[q[j]-'a']=j;
        }
        for(int j1=0;j1<26;j1++)
        for(int j2=0;j2<26;j2++){
            if(id[j1]>id[j2]){
                now_ans+=ans[j1][j2];
            }
        }
        printf("%lld\n",now_ans+ans2);
    }
    return 0;
}