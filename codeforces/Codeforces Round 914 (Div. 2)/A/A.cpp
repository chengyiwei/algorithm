#include<bits/stdc++.h>
using namespace std;
int flg[4][2]={{1,1},{-1,1},{1,-1},{-1,-1}};
typedef pair<int,int> pii;
map<pii,int> mp1,mp2;
void solve(){
    mp1.clear();mp2.clear();
    int a,b,q_x,q_y,k_x,k_y,ans=0;
    cin>>a>>b>>q_x>>q_y>>k_x>>k_y;
    pii p;
    for(int k=0;k<4;k++){
        p=make_pair(q_x+flg[k][0]*a,q_y+flg[k][1]*b);
        mp1[p]=1;
    }
    for(int k=0;k<4;k++){
        p=make_pair(q_x+flg[k][0]*b,q_y+flg[k][1]*a);
        mp1[p]=1;
    }
    
    for(int k=0;k<4;k++){
        p=make_pair(k_x+flg[k][0]*a,k_y+flg[k][1]*b);
        mp2[p]=1;
    }
    for(int k=0;k<4;k++){
        p=make_pair(k_x+flg[k][0]*b,k_y+flg[k][1]*a);
        mp2[p]=1;
    }
    
    for(auto it=mp2.begin();it!=mp2.end();++it){
        if(mp1.find(it->first)!=mp1.end()) ans++;
    }
    printf("%d\n",ans);
    return ;
}
int main(){
    freopen("A.in","r",stdin);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}