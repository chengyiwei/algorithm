#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("B.in" , "r" , stdin);
    int N; cin >> N;
    vector<string> S(N);
    int M = -1;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        M = max(M, (int)S[i].size());
    }
    vector<vector<char>> A(N, vector<char>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            A[i][j] = S[i][j];
        }
        for (int j = S[i].size(); j < M; j++) {
            A[i][j] = '*';
        }
    }
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            if (A[i][j] == '*') A[i][j] = ' ';
            else break;
        }
    }
    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i >= 0; i--) {
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}