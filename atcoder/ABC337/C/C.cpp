#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    int n=read();
    int hed;
    vector<int> nxt(n+1);
    for(int i=1;i<=n;i++){
        int x=read(); // x 是 Ai
        if(x==-1) hed=i;
        else nxt[x]=i;
    }
    for(int i=hed;i != 0;i=nxt[i])
        printf("%d ",i);
    return 0;
}