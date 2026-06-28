#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int F[maxn][maxn];
char s1[maxn],s2[maxn];
int min(int a,int b,int c){
    return min(a,min(b,c));
}
int main(){
    scanf("%s%s",s1+1,s2+1);
    int len1 = strlen(s1+1),len2 = strlen(s2+1);
    for(int i=1;i<=len1;i++)
        F[i][0] = i;
    for(int i=1;i<=len2;i++)
        F[0][i] = i;
    for(int i=1;i<=len1;i++)
        for(int j=1;j<=len2;j++)
            if(s1[i] == s2[j]) F[i][j] = F[i-1][j-1];
            else F[i][j] = min(F[i-1][j],F[i-1][j-1],F[i][j-1]) + 1;
    printf("%d\n",F[len1][len2]);
    return 0;
}