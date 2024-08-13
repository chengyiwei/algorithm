#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL x;cin>>x;
    stack<int> st;
    int f[]={0,2,4,6,8};
    x--;
    while(x){
        st.push(f[x%5]);
        x/=5;
    }
    if(st.empty()) putchar('0');
    else {
        while(!st.empty())
            putchar(st.top()+'0'),st.pop();
    }
}