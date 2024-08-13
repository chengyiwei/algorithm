#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("H.in","w",stdout);
    srand(GetTickCount());
    int T=1;
    printf("%d\n",T);
    int n=1000;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        printf("%d ",brand()%1000000000+1);
    }
    int siz=(n-1)*n/2;
    printf("\n%d\n",brand()%siz+1);
    return 0;
}