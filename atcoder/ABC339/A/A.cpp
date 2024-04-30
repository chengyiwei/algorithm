#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,p;
    cin>>s;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='.')break;
        p.push_back(s[i]);
    }
    for(int i=p.size()-1;i>=0;i--) cout<<p[i];
}