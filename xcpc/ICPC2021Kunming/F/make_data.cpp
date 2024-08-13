#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    srand(GetTickCount());
    freopen("F.in","w",stdout);
    int n=100000;
    printf("%d\n",n);
    for(int i=1;i<=n;i++) {
        int x=brand()%100000;
        if(brand()&1) x=-x;
        printf("%d ",x);
    }
    printf("\n");
    for(int i=2;i<=n;i++){
        int fa=brand()%(i-1)+1;
        printf("%d %d\n",i,fa);
    }
    return 0;
}