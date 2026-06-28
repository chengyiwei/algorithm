#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 4e5+5;
int a[maxn],b[maxn],lst[maxn];

int p[maxn],h[maxn];


int main(){
    freopen("E.in","r",stdin);
    srand(time(0));
    
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y; scanf("%d%d",&x,&y);
        if(x>y) swap(x,y); lst[y] = x;
        a[x] = i; a[y] = i;
        b[x] = 1; b[y] = 2;
    }
    for(int i=1;i<=n;i++) h[i] = rand();
    for(int i=1;i<=n;i++) h[i] ^= 2333;

    for(int i=1;i<=2*n;i++){
        if(b[i] == 1){
            p[i] = p[i-1] ^ h[a[i]];
        }
        else{
            p[i] = p[i-1] ^ h[a[i]];
            if(p[i] != p[lst[i]-1]){
                puts("Yes"); return 0;
            }
        }
    }
    puts("No");
    return 0;
}