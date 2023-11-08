#include<bits/stdc++.h>
#define int __int128
using namespace std;
int B;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void print(int x){
    stack<int> p;
    do{p.push(x%10);x/=10;}while(x);
    while(!p.empty()) putchar(p.top()+'0'),p.pop();
    putchar('\n');
}
signed main(){
    B=read();
    for(int i=1;i;i++){
        int C=1;
        for(int j=1;j<=i;j++){
            C*=i;
            if(C>B) {
                printf("-1\n");return 0;
            }
        }
        if(C==B){
            print(i);return 0;
        }
    }
    return 0;
}