#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    //直接插入排序
    for (int i = 2; i <= n; i++) {
        int temp = a[i], j = i;
        while (j > 1 && a[j - 1] > temp) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";

}