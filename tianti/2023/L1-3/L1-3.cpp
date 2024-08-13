#include <bits/stdc++.h>
using namespace std;
int main() {
	int A, B; cin >> A >> B;
	if (B == 0) {
		if (A == 0)
			cout << "biii\nstop" << endl;
		if (A == 1)
			cout << "dudu\nmove" << endl;
		if (A == 2)
			cout << "-\nstop" << endl;
	}  
	else {
		if (A == 0)
			cout << "-\nstop" << endl;
		if (A == 1)
			cout << "-\nmove" << endl;
		if (A == 2)
			cout << "-\nstop" << endl;
	}
	return 0;
} 
