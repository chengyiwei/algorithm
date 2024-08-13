#include<bits/stdc++.h>
using namespace std;
int N, M, day[200005];
const int INF = 0x3f3f3f3f;
int main(){
    cin >> N >> M;
    memset(day, INF, sizeof day);
    for (int i = 1; i <= M; i++)
    {
        int fire;
        cin >> fire;
        day[fire] = 0;
    }
    for (int i = N - 1; i; i--)
        day[i] = min(day[i], day[i+1] + 1);
    for (int i = 1; i <= N; i++)
        cout << day[i] << endl;
    return 0;
}