#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=1e9+7;
LL F[10000005];
int main(){
    freopen("B.in","r",stdin);
    LL N;
    cin>>N;
    F[1]=1;F[2]=7;
    if(N==1){printf("1\n");return 0;}
    if(N==2){printf("8\n");return 0;}
    for(int i=3;i<=N;i++)
        F[i]=((F[i-1]*7+F[i-2]))%TT;
    cout<<F[N-1]+F[N];
    return 0;
}