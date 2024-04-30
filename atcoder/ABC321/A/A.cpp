#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> A;
    while (N) {
        A.push_back(N % 10);
        N /= 10;
    }
    for (int i = 1; i < A.size(); i++)
        if (A[i] <= A[i - 1])
            return cout << "No\n", 0;
    cout << "Yes\n";
    return 0;
}