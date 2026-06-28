#include<bits/stdc++.h>
#include<ctime>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("L.in","w",stdout);
    srand(time(0));
    int N=100000;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        printf("%d ",brand()%(1<<30));
    }
}