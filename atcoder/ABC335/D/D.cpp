#include<bits/stdc++.h>
using namespace std;
const int flg[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
    int n,tot=0;
    cin>>n;
    vector<vector<int>> A(n+2,vector<int>(n+2,0));
    int x=1,y=1;A[x][y]=++tot;
    int k=0;
    for(int i=0;i<=n+1;i++) A[0][i]=A[n+1][i]=A[i][0]=A[i][n+1]=1;
    for(int i=1;i<n*n;i++){
        if(A[x+flg[k][0]][y+flg[k][1]]!=0) k=(k+1)%4;
        x+=flg[k][0],y+=flg[k][1];
        A[x][y]=++tot;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(A[i][j]==n*n){
                printf("T ");
            }
            else {
                printf("%d ",A[i][j]);
            }
        }
        printf("\n");
    }
}