#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int main(){
    // freopen("A.in","r",stdin);
    // char s[105];
    int T;
    string s;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        cin>>s;s=" "+s;
        int sum_A[maxn]={0},sum_B[maxn]={0};
        for(int i=1;i<=N;i++){
            sum_A[i]=sum_A[i-1]+(s[i]=='A');
            sum_B[i]=sum_B[i-1]+(s[i]=='B');
        }
        if(sum_B[N]==K){
            printf("0\n");
        }
        else if(sum_B[N]<K){
            int num=K-sum_B[N];
            for(int i=1;i<=N;i++){
                if(num==sum_A[i]){
                    printf("%d\n%d B\n",1,i);
                    break;
                }
            }
        }
        else {
            int num=sum_B[N]-K;
            for(int i=1;i<=N;i++){
                if(num==sum_B[i]){
                    printf("%d\n%d A\n",1,i);
                    break;
                }
            }
        }
    }
    return 0;
}