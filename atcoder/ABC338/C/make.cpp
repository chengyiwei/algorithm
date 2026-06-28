#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15)+rand();
}
int main(){
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    int n = 10;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        int x = brand()%100;
        printf("%d ",x);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        int x = brand()%100;
        printf("%d ",x);
    }
    printf("\n");
    
    for(int i=1;i<=n;i++){
        int x = brand()%100;
        printf("%d ",x);
    }
}