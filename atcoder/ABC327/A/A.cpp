#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;cin>>N;
    string a;
    cin>>a;
    int flg=0;
    for(int i=1;i<N;i++){
        if(a[i]=='a'&&a[i-1]=='b') flg=1;
        if(a[i]=='b'&&a[i-1]=='a') flg=1;
    }
    printf("%s\n",flg?"Yes":"No");
    return 0;
}