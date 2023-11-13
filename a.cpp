#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    if(N==1){
        printf("星期一");
    }
    else if(N==2){
        printf("星期二");
    }
    else if(N==3){
        printf("星期三");
    }
    else if(N==4){
        printf("星期四");
    }
    else if(N==5){
        printf("星期五");
    }
    else if(N==6){
        printf("星期六");
    }
    else if(N==7){
        printf("星期日");
    }
    else {
        printf("输入有误");
    }
}