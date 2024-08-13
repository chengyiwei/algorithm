#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 1000
typedef char ElemType;

#define OK 1
#define ERROR 0
typedef int Status;

typedef struct {
    ElemType *base;
    ElemType *top;
}Stack;

Status init_stack (Stack &S) {
    S.base = new ElemType[MAXSIZE];
    if (!S.base) return ERROR;
    S.top = S.base;
    return OK;
}

Status push (Stack &S, ElemType e) {
    if (S.top - S.base >= MAXSIZE) return ERROR;
    *S.top++ = e;
    return OK;
}

Status pop (Stack &S, ElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

Status get_top (Stack S, ElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

int main() {
    Stack S;
    init_stack(S);
    string s; getline(cin, s);
    for (auto c : s) {
        push(S, c);
    }
    string t;
    while (S.top != S.base) {
        char c;
        pop(S, c);
        t += c;
    }
    cout << s ;
    if (s == t) cout << "是回文。" << endl;
    else cout << "不是回文。" << endl;
    return 0;
}