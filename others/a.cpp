#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    int len=(N<<1)-1;
    for(int i=1;i<=N;i++){
        int now_len=(i<<1)-1;
        for(int j=1;j<=len-now_len>>1;j++)
            printf(" ");
        for(int j=1;j<=now_len;j++)
            printf("%d",i);
        printf("\n");
    }
    return 0;
}