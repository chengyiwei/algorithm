#include "testlib.h"
#include<cstring>
#include<iostream>
#include<cmath>
using namespace  std;

const int maxn=305;
int a[maxn][maxn],Max[maxn][maxn],Min[maxn][maxn];
int p[maxn];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    int in_N=inf.readInt();inf.readChar();

    for(int i=1;i<=in_N;i++)
    for(int j=i;j<=in_N;j++){
        a[i][j]=inf.readInt();
        inf.readChar();
    }
    
    for(int i=1;i<=in_N;i++){
        p[i]=ouf.readInt();
        ouf.readChar();
        Max[i][i]=Min[i][i]=p[i];
    }
    
    for(int i=1;i<=in_N;i++){
        for(int j=i+1;j<=in_N;j++){
            Max[i][j]=max(Max[i][j-1],p[j]);
            Min[i][j]=min(Min[i][j-1],p[j]);
            if(Max[i][j]-Min[i][j]!=a[i][j]) quitf(_wa, "The answer is wrong: L= %d R=%d",i, j);
        }
    }
    quitf(_ok, "The answer is correct.");

    return 0;
}
