#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
const int INF = 0x3f3f3f3f;
char A[maxn],B[maxn];
int F[maxn][maxn];
int main(){
    while(scanf("%s%s",A+1,B+1) != EOF){
        int n = strlen(A+1);
        for(int i=1;i<=n;i++) F[i][i] = 1;
        for(int len=2;len<=n;len++)
            for(int i=1;i+len-1<=n;i++){
                int j = i+len-1;
                F[i][j] = INF;
                if(B[i] == B[j])
                    F[i][j] = F[i][j-1];
                else
                    for(int k=i;k<j;k++)
                        F[i][j] = min(F[i][j], F[i][k] + F[k+1][j]);
            }
        for(int j=1;j<=n;j++){
            if(A[j] == B[j]) F[1][j] = F[1][j-1];
            else{
                for(int k=1;k<j;k++)
                    F[1][j] = min(F[1][j], F[1][k] + F[k+1][j]);
            }
        }
        printf("%d\n",F[1][n]);
    }
    return 0;
}