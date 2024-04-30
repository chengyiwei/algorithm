#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int fbrand(){
    int a=brand()%1000;
    if(rand()&1)return a;
    else return -a;
}
int main(){
    freopen("B.in","w",stdout);
    srand(GetTickCount());
    int T=brand()%100+1;
    printf("%d\n",T);
    while(T--){
        printf("%d %d\n",fbrand(),fbrand());
        printf("%d %d\n",fbrand(),fbrand());
        printf("%d %d\n",fbrand(),fbrand());
    }
    return 0;
}