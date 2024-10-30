#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    getchar();
    char a[1000],b[1000],c[1000];//三个数组分别是题目分值，题目答案，学生答案
    gets(a);
    gets(b);
    int i,j,sum[1000]={0},d[1000];//sum是学生总得分，d[1000]是学生每道题分值
    for(i=0;i<N;i++){
        gets(c);
        for(j=0;j<M;j++){
            if(c[j]==b[j]&&c[j]!=" "){
                d[j]=(a[j]-'0');//转换成整型计算
            }
            else if(c[j]==b[j]&&c[j]==' '){
                d[j]=0;
            }
            else if(c[j]!=b[j]){
                d[j]=0;
            }
            sum[i]+=d[j];
        }
    }
    for(i=0;i<N;i++){
        printf("%d\n",sum[i]);
    }
    return 0;
}