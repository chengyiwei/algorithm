#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    int N=3;
    printf("1\n");
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int x=rand()%1000;
        if(rand()&1)x=-x;
        printf("%d ",x);
    }
    
}