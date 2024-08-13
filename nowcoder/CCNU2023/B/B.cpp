#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        if((n&1)==1&&(m&1)==0)
            printf("NO\n");
        else 
            printf("YES\n");
    }
    return 0;
}