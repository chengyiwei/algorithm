#include<bits/stdc++.h>
using namespace std;
int main(){
    double M1,M2,L,r1,m;
    freopen("J.in","r",stdin);
    cin>>M1>>M2>>L>>m;
    r1=L/(sqrt(M2/M1)+1);
    printf("%.3lf",r1);
    return 0;
}