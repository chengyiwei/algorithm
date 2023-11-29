#include<bits/stdc++.h>
using namespace std;
int main(){
    string P="1";
    freopen((P+".in").c_str(),"r",stdin);
    freopen((P+".out").c_str(),"w",stdout);
    int N;
    scanf("%d",&N);getchar();
    char lst='0',now;
    for(int i=1;i<=N;i++){
        now=getchar();
        a[i]=now;
        if((now=='a'&&lst=='b')||(lst=='a'&&now=='b')) {printf("Yes\n");return 0;}
        lst=now;
    }
    printf("No");
    return 0;
}