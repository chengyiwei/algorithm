#include <bits/stdc++.h>
using namespace std;
int main() {
    int A,B; cin>>A>>B;
    int ans = 0;
    for (int i = A; i <= B; i++) {
        int x = i;
        while(x) {
            ans += x % 10;
            x /= 10;
        }
    }
    cout<<ans;
}