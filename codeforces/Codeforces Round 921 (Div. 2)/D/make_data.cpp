#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

typedef long long LL;

int brand(){
    return (rand()<<15)|rand();
}

void print(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int main(){
    freopen("D.in","w",stdout);
    srand(GetTickCount());
    int T = 1; 
    print(T);puts("");
    while(T--){
        int n,m,k; n = 100, m = 100, k = 100;
        print(n);putchar(' ');print(m);putchar(' ');print(k);puts("");
        for(int i=1;i<=m;i++){
            int a1 = rand()%n+1, a2 = rand()%n+1, f = brand()%1000000000+1;
            print(a1);putchar(' ');print(a2);putchar(' ');print(f);puts("");
        }

    }

}