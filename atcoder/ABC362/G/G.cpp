#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct AhoCorasick {
    struct Node {
        int fail, count, children[26];
        vector<int> end_ids;
    };
    vector<Node> trie;
    vector<int> results;
    vector<vector<int>> graph;
    int pattern_count;
    AhoCorasick(int num_patterns) : pattern_count(num_patterns) {
        trie.resize(1);
        results.resize(num_patterns);
    }
    void insert(const string& pattern, int id) {
        int current_node = 0;
        for (auto ch : pattern) {
            if (!trie[current_node].children[ch - 'a']) {
                trie.push_back({});
                trie[current_node].children[ch - 'a'] = trie.size() - 1;
            }
            current_node = trie[current_node].children[ch - 'a'];
        }
        trie[current_node].end_ids.push_back(id);
    }
    void build() {
        queue<int> q;
        graph.resize(trie.size() + 5);
        for (int i = 0; i < 26; i++) {
            if (trie[0].children[i]) q.push(trie[0].children[i]);
        }
        while (!q.empty()) {
            int current_node = q.front(); q.pop();
            for (int i = 0; i < 26; i++) {
                int &child_node = trie[current_node].children[i];
                if (child_node) {
                    trie[child_node].fail = trie[trie[current_node].fail].children[i];
                    q.push(child_node);
                } else {
                    child_node = trie[trie[current_node].fail].children[i];
                }
            }
        }
        for (int i = 1; i < trie.size(); i++) {
            graph[trie[i].fail].push_back(i);
        }
    }
    void search(string& text) {
        int current_node = 0;
        for (auto ch : text) {
            current_node = trie[current_node].children[ch - 'a'];
            trie[current_node].count++;
        }
    }
    void dfs(int node) {
        for (auto child : graph[node]) {
            dfs(child);
            trie[node].count += trie[child].count;
        }
        for (auto id : trie[node].end_ids) {
            results[id] = trie[node].count;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    string text; cin >> text;
    int num_patterns; cin >> num_patterns;
    AhoCorasick ac(num_patterns);
    for (int i = 0; i < num_patterns; i++) {
        string pattern; cin >> pattern;
        ac.insert(pattern, i);
    }
    ac.build();
    ac.search(text);
    ac.dfs(0);
    auto& results = ac.results;
    for (auto result : results) {
        cout << result << '\n';
    }
    return 0;
}
