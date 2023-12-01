#include <stdio.h>
#include <ctime>
int main(){
    for(int i=1;i<=10;i++)
        printf("%ld\n",CLOCKS_PER_SEC);
    return 0;
}