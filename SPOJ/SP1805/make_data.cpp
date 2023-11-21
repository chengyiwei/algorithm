#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("A.in","w",stdout);
    srand(GetTickCount());
    int N=1000000;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int now=2;
        printf("%d ",now);
    }
    return 0;
}