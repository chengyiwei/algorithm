#include<bits/stdc++.h>
using namespace std;
int num[]={1,0,0,0,1,0,1,0,2,1};
int big[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int sml[]={1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0};
int main(){
    // freopen("A.in","r",stdin);
    string s;
    cin>>s;
    int ans=0;
    for(auto x:s){
        if(x>='A'&&x<='Z') ans+=big[x-'A'];
        else if(x>='a'&&x<='z') ans+=sml[x-'a'];
        else ans+=num[x-'0'];
        // printf("%d\n",ans);
    }
    cout<<ans<<endl;
}