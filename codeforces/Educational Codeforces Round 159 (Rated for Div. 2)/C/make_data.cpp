#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long LL;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    printf("1\n");
    int N=200000;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int x=brand()%1000000000;
        if(brand()&1) x=-x;
        printf("%d ",x);
    }
}