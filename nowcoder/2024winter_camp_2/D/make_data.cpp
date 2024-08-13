#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int brand(){
    return (rand()<<15) + rand();
}

int main(){
    freopen("D.in","w",stdout);
    srand(GetTickCount());
    int T = 1;
    printf("%d\n",T);
    while(T--){
        int n = brand() % 5000 + 1, m = brand() % 1000 + 1, k = brand() % n + 1;
        printf("%d %d %d\n",n,m,k);
        while(m--){
            int a = brand() % n + 1, b = brand() % 1000 + 1;
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}