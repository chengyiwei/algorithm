#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("P9782.in","r",stdin);
    freopen("P9782.out","w",stdout);
    char ch1=getchar();
    getchar();
    char ch2=getchar();
    int a=ch1-'A',b=ch2-'A';
    int c=a+b;
    if(c>=26) putchar(c/26+'A');
    putchar(c%26+'A');
    return 0;
}