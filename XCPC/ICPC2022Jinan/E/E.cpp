#include<bits/stdc++.h>
using namespace std;
bool solve(){
    int n,k;cin>>n>>k;
    int s=n/2-(k/2)*(n/k); //  s 表示剩余偶数的个数
    if(s<=k/2&&s<=n%k) return 1; // 剩余都属的个数不能超过 k/2 ，并且不能超过 n%k
    return 0;
}
int main(){
    int T;cin>>T;
    while(T--) printf("%s\n",solve()?"Yes":"No");
}