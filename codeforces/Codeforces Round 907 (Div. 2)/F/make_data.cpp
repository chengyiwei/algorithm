#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("F.in","w",stdout);
    srand(GetTickCount());
    int T=2e4;
    printf("%d\n",T);
    while(T--){
    int N=10;
    int siz=1;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        if(brand()&1){
            int x=brand()%siz+1;
            printf("%d %d\n",1,x);siz++;
        }
        else {
            int x=brand()%siz+1;
            int val=brand()%1000000000;
            if(brand()&1) val=-val;
            printf("%d %d %d\n",2,x,val);
        }
    }
    }
    return 0;
}