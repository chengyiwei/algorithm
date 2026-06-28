#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return rand()<<15|rand();
}
int main(){
    freopen("I.in","w",stdout);
    srand(GetTickCount());
    int n,k;
    n=brand()%5+1,k=brand()%5+2;
    printf("%d %d\n",n,k);
    for(int i=1;i<=n;i++)
        printf("%d ",brand()%10+1);
    
}