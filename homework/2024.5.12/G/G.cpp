#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


int pos = 0;
void CreateBiTree(BiTree &T, string s) {
    if (pos >= s.size()) return;
    if (s[pos] == '*') {
        T = NULL;
        pos++;
    } else {
        T = new BiTNode;
        T->data = s[pos];
        pos++;
        CreateBiTree(T->lchild, s);
        CreateBiTree(T->rchild, s);
    }
}


int num_of_du_2 (BiTree T) {
    if (!T) return 0;
    if (T->lchild && T->rchild) return 1 + num_of_du_2(T->lchild) + num_of_du_2(T->rchild);
    return num_of_du_2(T->lchild) + num_of_du_2(T->rchild);
}

int main() {
    string s;
    while (cin >> s) {
        BiTree T;
        pos = 0;
        CreateBiTree(T, s);
        if (!T) {
            cout << 0 << endl;
            return 0;
        }
        cout << num_of_du_2(T) << endl;
    }

    return 0;
}