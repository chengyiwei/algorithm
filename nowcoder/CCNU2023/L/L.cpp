#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int maxn=1e6+5;
bool vis[maxn];
struct Bit{
    int x,id;
    bool b[31];
    void get_bit(){
        for(int i=0;i<31;i++) b[i]=x>>i&1;
    }
    bool operator <(const Bit &t) const {return id<t.id;}
}p[maxn];

int n;
int main(){
    freopen("L.in","r",stdin);
    int pos=30;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        Bit t;t.x=x;t.id=i;t.get_bit();
        p[i]=t;
    }
    while(pos>=0){
        int sum_now=0;
        for(int i=1;i<=n;i++)if(vis[i]==0)
            sum_now+=p[i].b[pos];
        if(sum_now<2) {pos--;continue;}
        for(int i=1;i<=n;i++)if(vis[i]==0){
            if(p[i].b[pos]==0)
                vis[i]=1;
        }
        pos--;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(ans1==0) ans1=i;
            else if(ans2==0) ans2=i;
            else break;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}