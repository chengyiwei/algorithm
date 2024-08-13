#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
bool check(string a,string b){
    if(a[0]=='0'||b[0]=='0') return 0;
    int A=0,B=0;
    for(int i=0;i<a.size();i++)
        A=A*10+a[i]-'0';
    for(int i=0;i<b.size();i++)
        B=B*10+b[i]-'0';
    if(B>A) return 1;
    return 0;
} 
void solve(){
    string s;cin>>s;
    for(int i=0;i<s.size()-1;i++){
        string a,b;
        for(int j=0;j<s.size();j++){
            if(j<=i) a.push_back(s[j]);
            else b.push_back(s[j]);
        }
        if(check(a,b)) {
            cout<<a<<" "<<b<<endl;
            return ;
        }
    }
    printf("-1\n");
    return ;
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--) solve();
}