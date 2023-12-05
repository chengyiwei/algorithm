#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
long long n,L=1;
int main(){
    cin>>n;
    for(long i=1;i<=n*2;i++){
        L+=i;
    }
    cout<<(L-n*2)%1000000007<<endl;
    
    return 0;
}
