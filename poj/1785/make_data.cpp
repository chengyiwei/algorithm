#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15)+rand();
}
int main(){
    freopen("1785.in","w",stdout);
    srand(GetTickCount());
    int n=100;
    printf("%d",n);
    while(n--)
        printf(" %d/%d",brand()%1000000000+1,brand()%1000000000+1);
    printf("\n0");
}