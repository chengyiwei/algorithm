#include<bits/stdc++.h>
using namespace std;
int main(){
    double v1,v2,V,a,PI=3.141593;
        v1=PI*4*4*4*(4/3.0)*1.0;
        v2=PI*10*10*10*(4/3.0)*1.0;
        V=v1+v2;
        a=pow(V,1.0/3);
        printf("%.4lf",a);
    return 0;
}