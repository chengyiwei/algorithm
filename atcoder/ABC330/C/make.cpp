#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()<<1);
}
int main(){
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    printf("%d\n",brand()%1000000);
    
}