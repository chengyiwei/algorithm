#include <bits/stdc++.h>
using namespace std;
typedef struct Node {
    int val;
    Node *next;
}Node, *LinkList;

void vector_to_List(vector<int> &a, LinkList &L) {
    L = new Node;
    Node *p = L;
    for (int i = 0; i < a.size(); i++) {
        Node *q = new Node;
        q->val = a[i];
        p->next = q;
        p = q;
    }
    p->next = NULL;
}

void print_List(LinkList L) {
    Node *p = L->next;
    while (p) {
        if (p->next == NULL)
            cout << p->val << endl;
        else
            cout << p->val << " ";
        p = p->next;
    }
}

void insert_List(LinkList &L, int pos, int x) { //在 pos 位后插入 x
    Node *p = L;
    for (int i = 0; i < pos; i++) {
        p = p->next;
        if (p == NULL) return ;
    }
    Node *q = new Node;
    q->val = x;
    q->next = p->next;
    p->next = q;
}

bool is_in_List(LinkList L, int x) {
    Node *p = L->next;
    while (p) {
        if (p->val == x) return true;
        p = p->next;
    }
    return false;
}

void order_insert_List (LinkList &L, int x) {
    Node *p = L;
    while (p->next && p->next->val < x) p = p->next;
    Node *q = new Node;
    q->val = x;
    q->next = p->next;
    p->next = q;
}

void delete_List (LinkList &L, int pos) { 
    Node *p = L;
    if (pos <= 0) return ;
    for (int i = 1; i < pos; i++) {
        p = p->next;
        if (p == NULL) return ;
    }
    Node *q = p->next;
    p->next = q->next;
    delete q;
}

void init_List(LinkList &L) {
    L = new Node;
    L->next = NULL;
}

int main() {
    LinkList L;
    init_List(L);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector_to_List(a, L);
    int x; cin >> x;
    if (!is_in_List(L, x))
        order_insert_List(L, x);
    print_List(L);
    return 0;
}
