#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int N = 1e9;
    int n = rnd.next(1, N);
    cout << n << endl;
}
