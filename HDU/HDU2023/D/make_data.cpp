#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("D.in","w",stdout);
    srand(GetTickCount());
    int T=1;
    printf("%d\n",T);
    int n=20,C=brand()%20+1;
    printf("%d %d\n",n,C);
    for(int i=1;i<=n;i++){
        printf("%d ",brand()%C+1);
    }
    return 0;
}