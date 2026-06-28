#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+5;
bool vis[maxn];
int min_turn[maxn]={0,1},max_mod4[4]={2,1,2,3};
inline void init(){
    for(int i=2;i<maxn;i++){
        if(!vis[i]){  //i是一个质数
            for(int j=1;j*i<maxn;j++)
                vis[i*j]=1;
            max_mod4[i%4]=i;
        }
        if(i&1)min_turn[i]=(i-max_mod4[i%4])/2+1;
        else min_turn[i]=i/2;
    }
}
int main(){
    init();
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int ans=maxn;
        for(int i=0;i<N;i++){
            int now;cin>>now;
            if(min_turn[now]/2<ans/2) //min_turn 是循环的轮数
                ans=min_turn[now];
        }
        printf("%s\n",ans&1?"Cody":"Loy");
    }
    return 0;
}