#include<bits/stdc++.h>
using namespace std;
int T,N,M;
string s,t;
bool check(string a){
    int len=a.size();
    for(int i=1;i<len;i++){
        if(a[i]==a[i-1])return 0;
    }
    return 1;
}
bool solve(){
    if(check(s))return 1;
    if(!check(t)) return 0;
    if(t[0]=='0'&&t[M-1]=='0'){
        for(int i=1;i<N;i++){
            if(s[i-1]=='0'&&s[i]=='0')
                return 0;
        }
        return 1;
    }
    else if(t[0]=='1'&&t[M-1]=='1'){
        for(int i=1;i<N;i++){
            if(s[i-1]=='1'&&s[i]=='1')
                return 0;
        }
        return 1;
    }
    else return 0;
}
int main(){
    // freopen("B.in","r",stdin);
    cin>>T;
    while(T--){
        cin>>N>>M;
        cin>>s>>t;
        printf("%s\n",solve()?"Yes":"No");
    }
    return 0;
}