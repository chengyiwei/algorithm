#include<bits/stdc++.h>
using namespace std;

string s;
int n, k;
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int L, R;
    while (L + 1 < R) {
        int mid = (R + L) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
}