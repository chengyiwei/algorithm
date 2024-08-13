#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4], b, c;
int main(){
    ios::sync_with_stdio(false);
    cin >> b >> c;
    if(b == c){
        cout << -1 << endl;
        return 0;
    }
    a[b] ++;
    a[c] ++;
    for(int i = 1; i <= 3; i ++){
        if(a[i] == 0){
            cout << i << endl;
            return 0;
        }
    }
}