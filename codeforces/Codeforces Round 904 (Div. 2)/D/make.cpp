#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return  (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("D.in","w",stdout);
    srand(GetTickCount());
    int T=brand()%10+1;
    printf("%d\n",T);
    while(T--){
        int N=brand()%20+1;
        printf("%d\n",N);
        for(int i=1;i<=N;i++){
            printf("%d ",brand()%N+1);
        }
        printf("\n");
    }
    return 0;
}