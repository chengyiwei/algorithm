#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("P4597.in","w",stdout);
    srand(GetTickCount());
    int N=1000;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int now=1;
        if(rand()&1) now=-now;
        printf("%d ",now);
    }
}