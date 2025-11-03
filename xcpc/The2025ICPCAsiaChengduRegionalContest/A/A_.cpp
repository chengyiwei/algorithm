#include <bits/stdc++.h>
using namespace std;

void f(int &x, int &y)
{
    swap(x, y);
}

int main()
{
    int x = 1, y = 2;
    printf("%p %p\n", &x, &y);
    f(x, y);
    cout << x << ' ' << y << '\n';
    printf("%p %p\n", &x, &y);
    return 0;
}