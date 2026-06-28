#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<int> a(n+1),f(n+1);
        for(int i=1;i<=n;i++) cin>>a[i],f[i]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                if(a[i] > a[j])
                    f[i] = max(f[i], f[j]+1);
        cout<<*max_element(f.begin(),f.end())<<endl;
    }
    return 0;
}