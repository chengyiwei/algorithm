#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15) | rand();
}
int main(){
    freopen("F.in","w",stdout);
    srand(GetTickCount());
    int n=6,m=2,k=2;
    printf("%d %d %d\n",n,m,k);
    for(int i=1;i<=n;i++)
        printf("%d ",brand()%n+1);
    printf("\n");
    return 0;
}