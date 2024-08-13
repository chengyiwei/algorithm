#include<bits/stdc++.h>
using namespace std;

int check1(string s){
    for(int i=0;i<s.size();i++)
        for(int j=i+1;j<s.size();j++)
            for(int k=j+1;k<s.size();k++)
                if(s[i]=='D' && s[j]=='F' && s[k]=='S')
                    return 1;
    return 0;
}

int check2(string s){
    for(int i=0;i<s.size();i++)
        for(int j=i+1;j<s.size();j++)
            for(int k=j+1;k<s.size();k++)
                if(s[i]=='d' && s[j]=='f' && s[k]=='s')
                    return 1;
    return 0;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    printf("%d %d\n",check1(s),check2(s));
}

int main(){
    freopen("A.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
}