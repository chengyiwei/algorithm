#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d%*c",&T);//%*c表示读入一个字符但不赋值
    string s[1000],now_s;
    for(int i=1;i<=T;i++)
        getline(cin,s[i]);
    getline(cin,now_s);
    for(int i=1;i<=T;i++){
        if(now_s==s[i]){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}