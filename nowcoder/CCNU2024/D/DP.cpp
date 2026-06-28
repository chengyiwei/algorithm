#include<bits/stdc++.h>
using namespace std;
int main(){
	int Tex = 1;
	while(1){
		cout << "Text " << Tex ++ << ": ";
		system("data.exe > data.in");
		system("Dstd.exe < data.in > Dstd.out");
		system("D.exe < data.in > D.out");
		if(system("fc Dstd.out D.out")){
			cout << "WA" << endl;
			return 0;
		}
		else cout << "AC" << endl;
	}
	return 0;
}
