#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y;
int main(){
    ios::sync_with_stdio(false);
    cin >> x >> y;
    if(x % 2 == 1 && y % 2 == 1){
        cout << (x + 1) / 2 + (y + 1) / 2 - 1 << endl;
    }
    else{
        cout << (x + 1) / 2 + (y + 1) / 2 << endl;
    }
    return 0;
}