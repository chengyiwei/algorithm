#include <bits/stdc++.h>
#define OK 1
#define ERROR 0
using namespace std;

typedef int Status;
typedef int ItemType;

typedef struct LNode {
    ItemType data;
    struct LNode *next;
} LNode, *LinkList;

Status init_list (LinkList &L) { // 创建一个空的列表L
    L = new LNode;
    L->next = NULL;
    return OK;
}

void creat_list (LinkList &L, int n) { // 在列表L中创建n个元素
    L = new LNode;
    L->next = NULL;
    auto p = L;
    for (int i = 0; i < n; i++) {
        auto q = new LNode;
        cin >> q->data;
        q->next = NULL;
        p->next = q;
        p = q;
    }
}

void vector_to_list (LinkList &L, vector<int>& A) {
    L = new LNode;
    L->next = NULL;
    auto p = L;
    for (int i = 0; i < A.size(); i++) {
        auto q = new LNode;
        q->data = A[i];
        q->next = NULL;
        p->next = q;
        p = q;
    }
}

LinkList merge_list (LinkList &L_A, LinkList &L_B) {
    auto p = L_A->next, q = L_B->next;
    auto L = new LNode;
    L->next = NULL;
    auto r = L;
    while (p && q) {
        if (p->data < q->data) {
            r->next = p;
            p = p->next;
        } else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    r->next = p ? p : q;
    return L;
}

void print_list (LinkList L) { // 打印列表L
    auto p = L->next;
    if (!p) {
        cout << "NULL";
        return;
    }
    while (p) {
        if (p->next != NULL && p->next->data == p->data) {
            p = p->next;
            continue;
        }
        cout << p->data;
        if (p->next) 
            cout << ' ';
        p = p->next;
    }
}

int main() {
    freopen ("C.in", "r", stdin);
    vector<int> A, B;
    for (;;) {
        int x; cin >> x;
        if (x == -1) break;
        A.push_back(x);
    }
    for (;;) {
        int x; cin >> x;
        if (x == -1) break;
        B.push_back(x);
    }
    LinkList L_A, L_B;
    vector_to_list(L_A, A); vector_to_list(L_B, B);
    auto merge = merge_list(L_A, L_B);
    print_list(merge);
    return 0;
}