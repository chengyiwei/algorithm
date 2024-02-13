#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;

int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

char s[maxn];

void solve(){
    int n=read(),k=read(),m=read();
    scanf("%s",s+1);
    vector<char> p;
    int a[26]={0};
    for(int i=1;i<=m;i++){
        a[s[i]-'a']=1;
        int flg = 1;
        for(int j=0;j<k;j++){
            flg &= a[j];
            if(!flg) break;
        }
        if(flg){
            p.push_back(s[i]);
            for(int j=0;j<k;j++)
                a[j]=0;
        }
    }
    if(p.size() >= n) {printf("YES\n");return ;}
    printf("NO\n");
    for(int i=0;i<p.size();i++)
        putchar(p[i]);
    char ch = 'a';
    for(int i=0;i<k;i++){
        if(!a[i])
            ch = 'a' + i;
    }
    for(int i=1;i<=n-p.size();i++)
        putchar(ch);
    putchar('\n');
}

int main(){
    freopen("C.in","r",stdin);
    int T=read();
    while(T--) solve();    
}