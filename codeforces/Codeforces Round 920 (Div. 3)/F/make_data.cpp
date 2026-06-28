#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15)|rand();
}

int main(){
    freopen("F.in","w",stdout);
    printf("1\n");
    srand(GetTickCount());
    int n=100000,Q=200000;
    printf("%d %d\n",n,Q);
    for(int i=1;i<=n;i++){
        int x=brand()%100000000;
        printf("%d ",x);
    }
    while(Q--){
        int s=brand()%100+1,d=brand()%100+1,k=brand()%100+1;
        while(s+d*(k-1)>n) s=brand()%n+1,d=brand()%n+1,k=brand()%n+1;
        printf("%d %d %d\n",s,d,k);
    }
}