#include<bits/stdc++.h>
using namespace std;
int a[15][15],N,M;
bool check(){
    map<int,int> mp;
    for(int i=1;i<=N;i++){
        mp.clear();
        for(int j=1;j<=M;j++) mp[a[i][j]]=1;
        if(mp.size()!=9) return 0;
    }
    for(int j=1;j<=M;j++){
        mp.clear();
        for(int i=1;i<=N;i++) mp[a[i][j]]=1;
        if(mp.size()!=9) return 0;
    }
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++){
        mp.clear();
        for(int ii=1;ii<=3;ii++)
        for(int jj=1;jj<=3;jj++){
            mp[a[(i-1)*3+ii][(j-1)*3+jj]]=1;
        }
        if(mp.size()!=9) return 0;
    }
    return 1;
}
int main(){
    freopen("C.in","r",stdin);
    N=9,M=9;
    for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++) cin>>a[i][j];
    printf("%s\n",check()?"Yes":"No");
    return 0;
}