#include <bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(NULL)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7;

struct Node{
    Node *next[2];
    int cnt = 0;
    bool finish = false;
    Node() {
        next[0] = next[1] = nullptr;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    ~Trie(){
        delete root;
    }
    void insert(int n){
        Node *curr = root;
        for(int i = 30; i >= 0; i--){
            int idx = n & (1 << i) ? 1 : 0;
            if(curr->next[idx] == nullptr)
                curr->next[idx] = new Node();
            curr = curr->next[idx];
            curr->cnt++;
        }
        curr->finish = true;
    }
    void erase(int n){
        Node *curr = root;
        for(int i = 30; i >= 0; i--){
            int idx = n & (1 << i) ? 1 : 0;
            curr = curr->next[idx];
            curr->cnt--;
        }
        if(curr->cnt == 0)
            curr->finish = false;
    }

    int query(int n){
        Node *curr = root;
        int ret = 0;
        for(int i = 30; i >= 0; i--){
            int idx = n & (1 << i) ? 0 : 1;
            if(curr->finish)
                break;
            if(curr->next[idx] && curr->next[idx]->cnt){
                ret |= (1 << i);
                curr = curr->next[idx];
            } else {
                curr = curr->next[1 ^ idx];
            }
        }
        return ret;
    }
};


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    int ans = 1e9;
    if(k == 0){
        cout << 1 << endl;
        return;
    }
    int left = 0;
    while(left < n){
        Trie trie;
        bool flag = false;
        for(int i = left; i < n; i++){
            trie.insert(arr[i]);
            if(trie.query(arr[i]) >= k){
                ll tmp = arr[i];
                for(int j = i-1; j >= left; j--){
                    if((tmp ^ arr[j]) >= k){
//                        cout << "idx : " << j << ' ' << i << endl;
                        ans = min(ans, i - j + 1);
                        left = j + 1;
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(!flag) break;
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G_.out", "w", stdout);
    fastio;
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}