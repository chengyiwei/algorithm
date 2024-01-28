#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    freopen("D.in","w",stdout);
    srand(GetTickCount());
    int n=4,m=5,k=3;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x=rand()%4;
            if(x==0||x==3) putchar('.');
            if(x==1) putchar('o');
            if(x==2) putchar('x');
        }
        puts("");
    }
}