#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) { // 构造一个空的链表
    L = new LNode;
    L->next = NULL;
    return true;
}

int Length(LinkList L) { // 返回链表的长度
    int len = 0;
    LNode *p = L;
    while (p->next) {
        len++;
        p = p->next;
    }
    return len;
}

LNode *GetElem(LinkList L, int i) { // 返回链表中第i个元素的地址
    LNode *p = L;
    int j = 0;
    while (p->next && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e) { // 返回链表中第一个值为e的元素的地址
    LNode *p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

bool ListInsert(LinkList &L, int i, ElemType e) { // 将值为 e 的元素插入到链表的第 i 个位置
    LNode *p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList &L, int i, ElemType &e) { // 删除链表中第 i 个位置的元素，并用 e 返回其值
    LNode *p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}

int main() {

}