#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, z;
    Node(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
};

struct cube {
    Node p1, p2;
    int volume() { return (p2.x - p1.x) * (p2.y - p1.y) * (p2.z - p1.z); }
    cube(Node p1 = Node(0,0,0), Node p2 = Node(0,0,0)) : p1(p1), p2(p2) {}
};


cube init(Node p) {
    return cube(p, Node(p.x + 7, p.y + 7, p.z + 7));
}

cube intersection (cube A, cube B) {
    cube C;
    C.p1.x = max(A.p1.x, B.p1.x); C.p2.x = min(A.p2.x, B.p2.x);
    C.p1.y = max(A.p1.y, B.p1.y); C.p2.y = min(A.p2.y, B.p2.y);
    C.p1.z = max(A.p1.z, B.p1.z); C.p2.z = min(A.p2.z, B.p2.z);
    C.p2.x = max(C.p1.x, C.p2.x); C.p2.y = max(C.p1.y, C.p2.y); C.p2.z = max(C.p1.z, C.p2.z);
    return C;
}


int main() {
    freopen ("E.in","r",stdin);
    int V1, V2, V3, V; cin >> V1 >> V2 >> V3; V = 7 * 7 * 7;
    if (V1 + 2 * V2 + 3 * V3 != 3 * V) {printf("No\n"); return 0;}
    Node a1 = Node(0,0,0), a2, a3;
    for (a2.x = -7; a2.x <= 7; a2.x ++)
        for (a2.y = -7; a2.y <= 7; a2.y ++)
            for (a2.z = -7; a2.z <= 7; a2.z ++)
                for (a3.x = 0; a3.x <= 14; a3.x ++)
                    for (a3.y = 0; a3.y <= 14; a3.y ++)
                        for (a3.z = 0; a3.z <= 14; a3.z ++) {
                            cube A = init(a1), B = init(a2), C = init(a3);
                            cube AB = intersection(A, B), AC = intersection(A, C), BC = intersection(B, C);
                            cube ABC = intersection(AB, C);
                            if (ABC.volume() == V3 && AB.volume() + AC.volume() + BC.volume() == V2 + 3 * V3){
                                printf("Yes\n");
                                printf("%d %d %d %d %d %d %d %d %d\n", a1.x, a1.y, a1.z, a2.x, a2.y, a2.z, a3.x, a3.y, a3.z);
                                return 0;
                            }
                        }
    printf("No\n");
    return 0;
}