#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
char str[5]="good!";
string s;
int main(){
    std::getline(std::cin,s);
    int L=s.size();
    for(int i=0;i<L/2;i++){
        if(s[i]!=s[L-i-1]) {printf("%s是不回文\n",s.c_str());return 0;}
    }
    printf("%s是回文\n",s.c_str());
}