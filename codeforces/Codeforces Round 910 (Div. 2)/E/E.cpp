#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s1[maxn],s2[maxn];
inline int solve(){
    int len_s1,len_s2;
    scanf("%d%d\n",&len_s1,&len_s2);
    scanf("%s%s",s1+1,s2+1);
    queue<int> mp[26];
    for(int i=1;i<=len_s1;i++) 
    mp[s1[i]-'a'].push(i);
    for(int i=1;i<=len_s2;++i){
        int now=s2[i]-'a';
        if(mp[now].empty()) {return 0;}
        int pos=mp[now].front();mp[now].pop();
        for(int j=0;j<now;++j){
            while(!mp[j].empty() && mp[j].front()<pos) 
                mp[j].pop();
        }
    }
    return 1;
}
int main(){
    // freopen("E.in","r",stdin);
    int T;cin>>T;
    while(T--) 
        printf("%s\n",solve()?"YES":"NO");
    return 0;
}