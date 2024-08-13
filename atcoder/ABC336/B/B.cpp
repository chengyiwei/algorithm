#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,cnt=0;cin>>x;
    while(x){
        if((x&1)==0) cnt++;
        else break;
        x>>=1;
    }
    printf("%d\n",cnt);
}