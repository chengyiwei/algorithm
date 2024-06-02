#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char ** argv){
	registerInteraction(argc, argv);
	int n = inf.readInt();	// chosen integer
	cout.flush();	// to make sure output doesn't stuck in some buffer
	int left = 40;
	bool found = false;
	int ans = -1;
	while(left > 0 && !found) {
		left --;
		int op = ouf.readInt(0, 1); 
		int a = ouf.readInt(1, 1000000000);
		if (op == 1) {
			ans = a;
			found = true;
			break;
		}
		if(a < n)
			cout << 0 << endl;
		else
			cout << 1 << endl;
		cout.flush();
	}
	if (!found)
		quitf(_wa, "couldn't guess the number with 50 questions");
	else if (ans != n)
		quitf(_wa, "couldn't guess the number");
	else
		quitf(_ok, "guessed the number with %d questions!", 50 - left);
}