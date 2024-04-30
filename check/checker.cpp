#include "testlib.h"
#include<cstring>
#include<iostream>
#include<cmath>
using namespace  std;


int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    double eps=1e-6;

    double user_out=ouf.readDouble();
    double std_out=ans.readDouble();
    
    if(fabs(user_out-std_out)<eps)
        quitf(_ok, "The answer is correct.");
    else
        quitf(_wa, "The answer is wrong: expected = %lf found = %lf",std_out, user_out);

    return 0;
}
