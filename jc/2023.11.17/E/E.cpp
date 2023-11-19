#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
typedef long long LL;
LL F[maxn],ans;
int N;
int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j*i<=N;j++){
            F[i*j]++;
        }
    }
    for(int i=1;i<=N;i++){
        ans+=F[i]*F[N-i];
    }
    cout<<ans<<endl;
    return 0;
}