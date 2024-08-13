#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15)|rand();
}
int main(){
    freopen("1542.in","w",stdout);
    srand(GetTickCount());
    int T=10;
    while(T--){
        int n=brand()%10;
        printf("%d\n",n);
        while(n--){
            double x1=brand()%100000,x2=brand()%100000,y1=brand()%100000,y2=brand()%100000;
            if(x1>x2) swap(x1,x2);
            if(y1>y2) swap(y1,y2);
            x1/=100;y1/=100;x2/=100;y2/=100;
            printf("%.2lf %.2lf %.2lf %.2lf\n",x1,y1,x2,y2);
        }
    }
    printf("0\n");
}