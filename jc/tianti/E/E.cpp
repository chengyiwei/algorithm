#include <bits/stdc++.h>
using namespace std;
struct Student {
    string name;
    int x, y, z, sum, id;
};

bool cmp(const Student &a, const Student &b) {
    if (a.sum != b.sum) return a.sum > b.sum;
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    if (a.z != b.z) return a.z > b.z;
    return a.id < b.id;
}

int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C.out", "w", stdout);
    int n; cin >> n;
    vector<Student> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i].name >> a[i].x >> a[i].y >> a[i].z; a[i].id = i;
        a[i].sum = a[i].x + a[i].y + a[i].z;
    }
    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; i ++) {
        cout << a[i].name << " " << a[i].x << " " << a[i].y << " " << a[i].z << '\n';
    }
    return 0;
}