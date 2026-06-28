#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
typedef pair<int,int> pii;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

char s[maxn];
map<pii,vector<int> > mp;
pii pos[maxn];

void check(){
    int x=read(),y=read(),l=read(),r=read();
    int x_=pos[r].first-x+pos[l-1].first,y_=pos[r].second-y+pos[l-1].second;

    auto& now1=mp[make_pair(x,y)];
    if(now1.size()>0){
        if(now1[0]<l||now1[now1.size()-1]>=r) {printf("YES\n");return ;}
    }
    auto& now2=mp[make_pair(x_,y_)];
    int pos_L=distance(now2.begin(),lower_bound(now2.begin(),now2.end(),l));
    if(pos_L<now2.size()&&now2[pos_L]<r) {printf("YES\n");return ;}

    printf("NO\n");
}
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int N=read(),Q=read();
    for(int i=1;i<=N;i++)
        s[i]=getchar();
    int x=0,y=0;
    pos[0]=make_pair(x,y);
    mp[pos[0]].push_back(0);
    for(int i=1;i<=N;i++){
        if(s[i]=='U') y++;
        if(s[i]=='D') y--;
        if(s[i]=='L') x--;
        if(s[i]=='R') x++;
        pos[i]=make_pair(x,y);
        mp[pos[i]].push_back(i);
    }
    for(int i=1;i<=Q;i++){
        check();
    }
}