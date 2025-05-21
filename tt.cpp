#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
using namespace std;

map<int, bool> exist;  // Whether a node exists
map<int, bool> odd;    // Parity from parent to this node
map<int, int> prev;    // Parent link in union-find

bool add(int a, int b, bool c) { // add constraint: parity from a-1 to b is c
    if (!exist[b]) {
        exist[b] = true;
        odd[b] = c;
        prev[b] = a;
        return true;
    }
    int i = prev[b];
    if (i == a) return (odd[b] == c);
    if (i < a) return add(i, a - 1, c != odd[b]);
    return add(a, i - 1, c != odd[b]);
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == -1) break;

        int q;
        cin >> q;
        exist.clear();
        odd.clear();
        prev.clear();

        bool contradiction = false;
        for (int i = 0; i < q; ++i) {
            int a, b;
            string ans;
            cin >> a >> b >> ans;
            bool parity = (ans == "odd");

            if (!contradiction) {
                if (!add(a - 1, b, parity)) {
                    cout << i << endl; // i is 0-based, so i-th means (i+1)-th question is invalid
                    contradiction = true;
                }
            }
        }

        if (!contradiction) {
            cout << q << endl;
        }
    }
    return 0;
}

