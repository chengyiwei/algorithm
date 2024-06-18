#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char * argv[]){
	setName("Guess the number");
	registerInteraction(argc, argv);
	rnd.setSeed(time(NULL));
	int n = rnd.next(1, 1000000000);	// chosen integer
    int x = rnd.next(1, n);
    cout << n << endl;
	int left = 50;
	bool found = false;
	int ans = -1;
	while(left > 0 && !found) {
		left --;
		int op = ouf.readInt(0, 1); 
		int a = ouf.readInt(1, n);
		if (op == 1) {
			ans = a;
			found = true;
			break;
		}
		if(a < x)
			cout << 0 << endl;
		else
			cout << 1 << endl;
		cout.flush();
	}
	if (!found)
		quitf(_wa, "couldn't guess the number with 50 questions");
	else if (ans != x)
		quitf(_wa, "couldn't guess the number");
	else
		quitf(_ok, "guessed the number with %d questions!", 50 - left);
}
