#include<bits/stdc++.h>
using namespace std;
const int maxn =  1e3 + 10;
int F[maxn][maxn];
char s1[maxn],s2[maxn];
int main(){
    freopen("1159.in","r",stdin);
    while(~scanf("%s%s",s1+1,s2+1)){
        int len1 = strlen(s1+1),len2 = strlen(s2+1);
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
                if(s1[i]==s2[j]) F[i][j] = F[i-1][j-1]+1;
                else F[i][j] = max(F[i-1][j],F[i][j-1]);
        printf("%d\n",F[len1][len2]);
    }
    return 0;
}