#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;  cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    for(int &i: c) cin >> i;

    map<int,int> occ;
    for(int i: a) occ[i]++;

    long long validPairs = 0;
    for(int cj: c) validPairs += occ[b[cj- 1]];
    cout << validPairs << '\n';
}
