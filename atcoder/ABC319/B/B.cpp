#include<bits/stdc++.h>
using namespace std;
int ans[1005],N;
int main(){
    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);
    cin >> N;
    for (int i = 0; i <= N;i++)
        ans[i] = -1;
    for (int j = 1; j < 10;j++)if(N%j==0){
        int i = N / j;
        for (int k = 0; k <= N;k+=i)if(ans[k]==-1)
            ans[k] = j;
    }
    for (int i = 0; i <= N;i++)
        if(ans[i]==-1)
            printf("-");
        else
            printf("%d", ans[i]);
    return 0;
}