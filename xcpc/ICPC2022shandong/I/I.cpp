#include <bits/stdc++.h>
using namespace std;
int a[7] = {-1,1,0,0,1,0,0};

int main() {
    int A, B; cin >> A >> B;
    
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            for (int k = 1; k <= 6; k++) {
                vector<int> p(2);
                p[a[i]] += i;
                p[a[j]] += j;
                p[a[k]] += k;
                if (p[0] == B && p[1] == A) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
    cout << "No" << endl;
    return 0;
}