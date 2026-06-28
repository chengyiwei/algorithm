#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int T,N,flg;
string X,Y;
bool check(){
    int num_xa,num_xb,num_ya,num_yb,num_xc;
    cin>>N>>X>>Y;
    X="C"+X+"C";
    Y="C"+Y+"C";
    N=X.size();
    int L=0,R=0;
    num_xa = num_xb = num_xc = num_ya = num_yb = 0;
    for(int i=0;i<N;i++)
        if(Y[i]=='C'){
            if(X[i]!='C') return 0;
            if(num_xa > num_ya) return 0;
            if(num_xb > num_yb) return 0;
            L=R;R=i;
            int C_A = num_ya - num_xa;
            for(int j=L;j<=R;j++)if(Y[j] != 'C' && X[j] == 'C'){
                if(C_A) X[j] == 'A', C_A--;
                else X[j] == 'B';
            }
            num_xb = num_yb = num_xc = 0;
        }
        else {
            num_xb += (X[i]=='B'); num_xc += (X[i]=='C'); num_xa += (X[i]=='A');
            num_yb += (Y[i]=='B'); num_ya += (Y[i]=='A');
        }
    
    num_xb = num_yb = 0;
    for(int i=0;i<N;i++)
        if(Y[i]=='C'){
            num_xb = num_yb = 0;
        }
        else {
            num_xb += (X[i]=='B');num_yb += (Y[i]=='B');
            if(num_xb > num_yb) return 0;
        }
    
    num_xa = num_ya = 0;
    for (int i=N;i>=0;i--)
        if(Y[i]=='C'){
            num_xa = num_ya = 0;
        }
        else {
            num_xa += (X[i]=='A');num_ya += (Y[i]=='A');
            if(num_xa > num_ya) return 0;
        }
    return 1;
}
int main(){
    freopen("A.in","r",stdin);
    cin>>T;
    while(T--){
        printf("%s\n",check()?"Yes":"No");
    }
    return 0;
}