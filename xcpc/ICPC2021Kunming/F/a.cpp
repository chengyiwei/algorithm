#include<bits/stdc++.h>
int main(){
    int i=0;
    for(;;){
        i++;
        if((double)clock()/CLOCKS_PER_SEC>=0.95 )break;
    }
    printf("%d\n",i);
}