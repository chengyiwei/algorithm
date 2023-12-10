#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("A.in","w",stdout);
    srand(GetTickCount());
    int N=5;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int x=brand()%10;
        if(brand()&1) x=-x;
        printf("%d ",x);
    }
    printf("\n");
    for(int i=2;i<=N;i++){
        printf("%d ",brand()%(i-1)+1);
    }
    
}