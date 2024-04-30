#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return rand()<<15|rand();
}
int main(){
    freopen("4614.in","w",stdout);
    srand(GetTickCount());
    int T=1;
    printf("%d\n",T);
    while(T--){
        int n=5,m=10;
        printf("%d %d\n",n,m);
        while(m--){
            int op=brand()%2;
            if(op==0){
                int A=brand()%n,B=brand()%n;
                printf("%d %d %d\n",op+1,A,B);
            }
            else{
                int A=brand()%n,B=brand()%n;
                if(A>B) swap(A,B);
                printf("%d %d %d\n",op+1,A,B);
            }
        }
    }
}