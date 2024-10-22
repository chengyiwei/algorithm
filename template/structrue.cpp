#include<bits/stdc++.h>

struct DSU { // 简单的一个并查集类
    std::vector<int> f;
    std::vector<int> size;
 
    DSU(int n) : f(n), size(n) {
        std::iota(f.begin(), f.end(), 0);
        std::fill(size.begin(), size.end(), 1);
    }
 
    int find(int x) { // 路径压缩
        while (x != f[x])
            x = f[x] = f[f[x]];
        return x;
    }
 
    void Union(int x, int y) {
        if (find(x) == find(y))
            return;
        if (size[x] < size[y]) // 按秩合并
            std::swap(x, y);
 
        size[find(x)] += size[find(y)];
        f[find(y)] = find(x);
    }
};

int main() {}