#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("P4597.in","w",stdout);
    srand(GetTickCount());
    int N=100000;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int now=brand()%1000000000;
        if(rand()&1) now=-now;
        printf("%d ",now);
    }
}