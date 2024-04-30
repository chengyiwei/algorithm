#include<bits/stdc++.h>
using namespace std;
string p[3]={"hzy","zzy","syh"};
int main(){
    string s;cin>>s;
    int ans=0;
    if(s.size()<3) return puts("0"),0;
    for(int i=0;i<=s.size()-3;i++){
        for(int k=0;k<3;k++){
            if(s.substr(i,3)==p[k]) ans++;
        }
    }
    cout<<ans*3<<endl;
}