#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
    freopen("a.in","w",stdout);
    srand(GetTickCount());
    int N=500000;
    printf("%d\n",N);
    for(int i=1;i<=N;i++){
        int now=rand()%(26-2);
        putchar(now+'c');
    }
}