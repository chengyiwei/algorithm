#include <bits/stdc++.h>
using namespace std;
int main() { 
    int N; cin >> N;
    vector<pair<string, int> > a(N);
    long long T = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i].first >> a[i].second;
        T += a[i].second;
    }
    sort(a.begin(), a.end());
    cout << a[T % N].first << endl;
    return 0;
}