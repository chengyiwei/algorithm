#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        system("./make_data");
        system("./A");
        system("./A0");
        if(system("diff A.out A0.out")){
            cout << "WA" << endl;
            return 0;
        }
        else{
            cout << "AC" << endl;
        }
    }
}