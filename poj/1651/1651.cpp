#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long LL;
const int maxn = 105;
const LL INF = 1e18;
typedef long long LL;

int n;
LL F[maxn][maxn];
int a[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    for(int L=3;L<=n;L++)
        for(int i=1;i+L-1<=n;i++){
            int j = i+L-1;
            F[i][j] = INF;
            for(int k=i+1;k<j;k++)
                F[i][j] = min(F[i][j], F[i][k] + F[k][j] + a[i]*a[k]*a[j]);
        }       
    printf("%lld\n",F[1][n]);
    return 0;    
}