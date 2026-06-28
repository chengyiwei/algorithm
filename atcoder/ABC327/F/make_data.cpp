#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}
int main(){
    freopen("F.in", "w", stdout);
    srand(GetTickCount());
    int N = 100, D=20,W=20;
    printf("%d %d %d\n", N,D,W);
    for(int i=1;i<=N;i++){
        int T=brand()%50+1,X=brand()%50+1;
        printf("%d %d\n",T,X);
    }
    return 0;
}