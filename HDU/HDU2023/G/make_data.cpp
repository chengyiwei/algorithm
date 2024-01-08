#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("G.in","w",stdout);
    srand(GetTickCount());
    int T=10;
    printf("%d\n",T);
    while(T--){
        int n=30,m=30,K=2;
        printf("%d %d %d\n",n,m,K);
        int h=4,ed_x=brand()%n+1,ed_y=brand()%m+1;
        for(int k=1;k<=K;k++)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i==n&&j==m)||(i==ed_x&&j==ed_y)) {putchar('.');continue;}
                if(brand()%3==0) putchar('*');
                else putchar('.');
            }
            putchar('\n');
        }
        printf("%d %d %d\n",n,ed_x,ed_y);
    }
}