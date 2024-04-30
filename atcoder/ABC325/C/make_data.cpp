#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    int N=1000,M=1000;
    printf("%d %d\n",N,M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            printf(".");
        printf("\n");
    }
}