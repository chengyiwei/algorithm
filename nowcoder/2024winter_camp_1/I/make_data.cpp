#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<15) + rand();
}
bool check(int x){
    return x>=-100 && x<=100;
}

void solve1(){
    int n = 100000;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        int x,y,r; x = brand()%100; y = brand()%100; r = brand()%100; if(brand()&1) x=-x; if(brand()&1) y=-y;
        while( !(check(x-r) && check(x+r) && check(y-r) && check(y+r))){
            r = brand()%100;
        }
        printf("%d %d %d\n",x,y,r);
    }
}

void solve2(){
    int n = 100000;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        int x,y,r; x = brand()%100; y = brand()%100; r = brand()%100; if(brand()&1) x=-x; if(brand()&1) y=-y;
        while( !(check(x-r) && check(x+r) && check(y-r) && check(y+r))){
            x = brand()%100; y = brand()%100; r = brand()%100; if(brand()&1) x=-x; if(brand()&1) y=-y;
        }
        printf("%d %d %d\n",x,y,r);
    }
}

int main(){
    freopen("H.in","w",stdout);
    srand(GetTickCount());
    if(brand()&1) {
        solve1();
        freopen("H0.out","w",stdout);
        printf("bit-noob\n");
    }
    else {
        solve2();
        freopen("H0.out","w",stdout);
        printf("buaa-noob\n");
    }
}