#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
    int T=read();
    long long A =0,B =0;
    for(int i=1;i<=T;i++){
        A+=read(); B+=read();
    }
    if(A>B)
        printf("Takahashi\n");
    else if(A<B)
        printf("Aoki\n");
    else
        printf("Draw\n");
    
}