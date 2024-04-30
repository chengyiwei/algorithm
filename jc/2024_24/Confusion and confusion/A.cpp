#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 1e5;
    double S = 200 * 200, s = S/2, L = sqrt(s)/2;
    int ret =  0;
    for(int i = 1; i <= n; i ++){
        double x, y, r;
        scanf("%lf %lf %lf\n", &x, &y, &r);
        if(-L < x && x < L && -L < y && y < L) 
            ret++;
    }
    if(1.0 * ret / n > 0.6) 
        printf("2333zy\n");
    else
        printf("L1n_1000\n");
}