#include <bits/stdc++.h>
using namespace std;

typedef char ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree &T) {
    ElemType ch;
    cin >> ch;
    if (ch == '#') T = NULL;
    else {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreOrderTraverse(BiTree T) {
    if (T) {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}

int num_of_leaves(BiTree T) {
    if (!T) return 0;
    if (!T->lchild && !T->rchild) return 1;
    return num_of_leaves(T->lchild) + num_of_leaves(T->rchild);
}

int depth(BiTree T) {
    if (!T) return 0;
    return max(depth(T->lchild), depth(T->rchild)) + 1;
}

int main() {
    BiTree T;
    CreateBiTree(T);
    if (!T) {
        cout << 0 << endl;
        return 0;
    }
    cout << "PreOrder:";
    PreOrderTraverse(T);
    cout << endl;
    cout << "InOrder:";
    InOrderTraverse(T);
    cout << endl;
    cout << "PostOrder:";
    PostOrderTraverse(T);
    cout << endl;
    cout << "Depth:" << depth(T) << endl;
    cout << "Leaf:" << num_of_leaves(T);
    return 0;
}