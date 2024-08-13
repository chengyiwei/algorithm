#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    int N=read();
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
        if(s[i]=='0') {
            printf("YES\n");return ;
        }
    printf("NO\n");
}
int main(){
    int T=read();
    while(T--) solve();
}