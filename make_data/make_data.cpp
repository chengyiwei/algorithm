#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()<<1);
}
typedef pair<int,int> pii;
map<pii,bool> mp;
int main(){
    freopen("a.in","w",stdout);
    srand(GetTickCount());
    int n=100,m=3000;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++){
        int x=brand()%n+1,y=brand()%n+1;
        while(mp[make_pair(x,y)]){
            x=brand()%n+1,y=brand()%n+1;
        }
        mp[make_pair(x,y)]=1;
        mp[make_pair(y,x)]=1;
        printf("%d %d %d\n",x,y,brand()%1000000000);
    }
}