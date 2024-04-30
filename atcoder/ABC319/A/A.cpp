#include<bits/stdc++.h>
using namespace std;
struct A
{
    string s;
    int rating;
}a[15];

int main(){
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    a[1].s = (string)"tourist";a[1].rating = 3858;
    a[2].s = (string)"ksun48";a[2].rating = 3679;
    a[3].s = (string)"Benq";a[3].rating = 3658;
    a[4].s = (string)"Um_nik";a[4].rating = 3648;
    a[5].s = (string)"apiad";a[5].rating = 3638;
    a[6].s = (string)"Stonefeang";a[6].rating = 3630;
    a[7].s = (string)"ecnerwala";a[7].rating = 3613;
    a[8].s = (string)"mnbvmar";a[8].rating = 3555;
    a[9].s = (string)"newbiedmy";a[9].rating = 3516;
    a[10].s = (string)"semiexp";a[10].rating = 3481;


    string now;
    cin >> now;
    for (int i = 1; i <= 10;i++){
        if(now==a[i].s){
            cout << a[i].rating;
            return 0;
        }
    }
    return 0;
}