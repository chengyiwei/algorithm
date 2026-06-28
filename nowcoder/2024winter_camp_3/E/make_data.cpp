#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15) + rand();
}
int main(){
    freopen("E.in", "w", stdout);
    srand(GetTickCount());
    int n = 5, k = brand() & 1;
    printf("%d %d\n", n, k);
    for(int i = 1; i <= n; i++)
        printf("%d ", brand() % 1000 - 500);
    return 0;
}