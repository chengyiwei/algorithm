#include<bits/stdc++.h>
using namespace std;
int F[maxn],a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++){
            if(abs(a[j]-a[i]) <= D)
                F[i] = max(F[i],F[j]+1);
        }
}
//O(n*n)