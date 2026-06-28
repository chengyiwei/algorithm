#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,x,y,z,t;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    cout<<s.size()<<'\n';
    for(int i=0;i<s.size();i++){
        if(s[i]<='Z'&&s[i]>='A'){
            cout<<"3 0 ";
            if(s[i]<='J'&&s[i]>='A'){
                cout<<0<<' '<<s[i]-'A'<<'\n';
            }
            if(s[i]<='S'&&s[i]>='K'){
                cout<<1<<' '<<s[i]-'J'<<'\n';
            }
            if(s[i]<='Z'&&s[i]>='T'){
                cout<<2<<' '<<s[i]-'S'<<'\n';
            }
        }
        else{
            if(s[i]<='j'&&s[i]>='a'){
                cout<<0<<' '<<s[i]-'a'<<'\n';
            }
            if(s[i]<='s'&&s[i]>='k'){
                cout<<1<<' '<<s[i]-'j'<<'\n';
            }
            if(s[i]<='z'&&s[i]>='t'){
                cout<<2<<' '<<s[i]-'s'<<'\n';
            }
        }
    }
    return 0;
}
