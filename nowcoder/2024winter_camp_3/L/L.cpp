#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int ans = 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) if(i != j){
            int x;
            if(a[j] != 10)
                x = a[i] * 10 + a[j];
            else
                x = a[i] * 100 + a[j];
            if (x % 36 == 0)
                ans ++;
        }
    cout << ans << endl;
    return 0;
}