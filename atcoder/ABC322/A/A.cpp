#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int i = 0; i < N-2; i++){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
            printf("%d\n",i+1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}