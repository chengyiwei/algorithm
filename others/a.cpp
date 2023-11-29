#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=1e9+7;


inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main() {
    LL N;
    cin>>N;
    cout<<(2*N*N-N+1)%TT<<endl;
    return 0;
}