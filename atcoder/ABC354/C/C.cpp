#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("C.in", "r", stdin);
    int N; cin >> N;
    vector<int> A(N + 1), C(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> A[i] >> C[i];
    vector<int> idx(N + 1);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin() + 1, idx.end(), [&](int i, int j) {
        return A[i] < A[j] || (A[i] == A[j] && C[i] < C[j]);
    });
    stack<int> st;
    for (int i = 1; i <= N; i++) {
        int id = idx[i];
        while (!st.empty() && C[st.top()] > C[id]) 
            st.pop();
        st.push(id);
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) 
        cout << i << " ";
    return 0;
}