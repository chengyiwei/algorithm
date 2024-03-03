#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand() {
    return (rand()<<15) + rand();
}
int main() {
    freopen ("F.in", "w", stdout);
    srand(GetTickCount());
    int t = brand() % 10 + 1;
    printf("%d\n",t);
    while (t--) {
        int n = brand() % 1000 + 1;
        printf("%d\n",n);
        for (int i = 1; i <= n; i++) {
            printf("%d ",brand() % 100 + 1);
        }
        printf("\n");
    }
    
}