#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; scanf("%d",&n);
    if(n%6 == 0)
        printf("%d\n",n/6);
    else
        printf("%d\n",(n/6)*2);
    return ;
}
int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}