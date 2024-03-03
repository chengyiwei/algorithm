#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("F0.out","r",stdin);
    freopen("check.out","w",stdout);
    
    int n,m, t = 0; 
    while(scanf("%d%d",&n,&m) != EOF){
        t++;
        if (n == -1 && m == -1) {
            continue;
        }
        vector<int> a(n),b(m);
        for (int i = 0; i < n; i++) scanf("%d",&a[i]);
        for (int i = 0; i < m; i++) scanf("%d",&b[i]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if(__gcd(a[i], b[j]) != 1) {
                    for (int i = 0; i < n; i++)
                        printf("%d ",a[i]);
                    printf("\n");
                    for (int i = 0; i < m; i++)
                        printf("%d ",b[i]);
                    printf("%d %d\n",n,m);
                    printf("%d %d\n", i, j);
                    printf("%d %d %d %d\n",t,a[i],b[j],__gcd(a[i], b[j]));
                    printf("0\n");
                    return 0;
                }
            }
    }
    printf("1\n");
    return 0;
}