#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int brand(){
    return (rand()<<16)+(rand()<<1)+(rand()&1);
}
int main(){
    freopen("K.in","w",stdout);
    srand(GetTickCount());
    int N=5,Q=10;
    printf("%d %d\n",N,Q);
    for(int i=1;i<=N;i++){
        string s;
        int len=brand()%5+1;
        for(int j=1;j<=len;j++){
            s.push_back(brand()%26+'a');
        }
        cout<<s<<endl;
    }
    int p[26];
    for(int i=0;i<26;i++) p[i]=i;
    for(int i=1;i<=Q;i++){
        for(int j=0;j<26;j++) putchar(p[j]+'a');
        putchar('\n');
        random_shuffle(p,p+26);
    }
    return 0;
}