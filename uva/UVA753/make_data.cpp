#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()<<1);
}
int main(){
    freopen("UVA753.in","w",stdout);
    srand(GetTickCount());
    int T=100;
    printf("%d\n",T);
    while(T--){
        int N=20,M=20,K=20;
        printf("%d\n",N);
        for(int i=1;i<=N;i++){
            printf("%c\n",brand()%26+'A');
        }
        printf("%d\n",M);
        for(int i=1;i<=M;i++){
            printf("A %c\n",brand()%26+'A');
        }
        printf("%d\n",K);
        for(int i=1;i<=K;i++){
            printf("%c %c\n",brand()%26+'A',brand()%26+'A');
        }
    }
}