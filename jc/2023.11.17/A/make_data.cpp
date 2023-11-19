#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    freopen("A.in","w",stdout);
    srand(GetTickCount());
    int N=300,M=800;
    printf("%d %d\n",N,M);
    for(int i=1;i<=M;i++){
        int x=rand()%N+1,y=rand()%N+1,z=rand()%1000+1;
        printf("%d %d %d\n",x,y,z);
    }
    
}