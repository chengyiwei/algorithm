#include<bits/stdc++.h>
using namespace std;

int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

bool check(string s){
    for(int i=0;i<s.size()-1;i++)
        if(s[i]>s[i+1])
            return 0;
    return 1;
}

void solve(){
    int n=read();
    vector<int> pos[26];
    vector<int> b;
    vector<char> c;
    string s;
    cin>>s;
    if(check(s)) {printf("0\n");return ;}
    for(int i=0;i<s.size();i++)
        pos[s[i]-'a'].push_back(i);
    int now_pos=-1;
    for(int i=25;i>=0;i--){
        for(int j=0;j<pos[i].size();j++){
            if(now_pos<pos[i][j]) {
                now_pos=pos[i][j];
                b.push_back(now_pos);
                c.push_back(i+'a');
            }
        }
    }
    sort(c.begin(),c.end());
    for(int i=0;i<b.size();i++)
        s[b[i]]=c[i];
    if(!check(s)){printf("-1\n");return ;}

    printf("%d\n",b.size()-pos[c[c.size()-1]-'a'].size());
    return ;
}
int main(){
    freopen("C.in","r",stdin);
    int T=read(); 
    while(T--) solve();
    return 0;
}