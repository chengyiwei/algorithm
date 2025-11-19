#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n <= 100) {
            bool found = false;
            for (int i = 0; i < n && !found; i++) {
                for (int j = i + 1; j < n && !found; j++) {
                    int x = a[i];
                    int y = a[j];
                    if (y % x % 2 == 0) {
                        cout << x << " " << y << endl;
                        found = true;
                    }
                }
            }
            if (!found) {
                cout << -1 << endl;
            }
        } else {
            if (a[0] == 1) {
                cout << a[0] << " " << a[1] << endl;
                continue;
            }
            
            int even_count = 0;
            int even_value = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0) {
                    even_count++;
                    if (even_value == -1) {
                        even_value = a[i];
                    }
                }
            }
            if (even_count >= 2) {
                int first_even = -1;
                int second_even = -1;
                for (int i = 0; i < n; i++) {
                    if (a[i] % 2 == 0) {
                        if (first_even == -1) {
                            first_even = a[i];
                        } else if (second_even == -1) {
                            second_even = a[i];
                            break;
                        }
                    }
                }
                cout << first_even << " " << second_even << endl;
                continue;
            }
            
            vector<int> odds;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 1) {
                    odds.push_back(a[i]);
                }
            }
            bool found = false;
            if (odds.size() >= 2) {
                for (int i = 0; i < odds.size() - 1; i++) {
                    int x = odds[i];
                    int y = odds[i + 1];
                    if (y < 2 * x) {
                        cout << x << " " << y << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                continue;
            }
            
            if (even_count == 1) {
                vector<int> small_odds;
                for (int i = 0; i < n; i++) {
                    if (a[i] % 2 == 1 && a[i] < even_value) {
                        small_odds.push_back(a[i]);
                    }
                }
                int limit = min(100, (int)small_odds.size());
                for (int i = 0; i < limit; i++) {
                    int x = small_odds[i];
                    int k = even_value / x;
                    if (k % 2 == 0) {
                        cout << x << " " << even_value << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}