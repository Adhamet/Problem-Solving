#include <iostream>
#include <string>
using namespace std;

// For k = 0: "ab" (merging them costs 0)
// For k = 1: "aa" (merging them costs 1)
// For k = 2: "aaa" (merging aa+a costs 2)
// For k = 3: "aaaa" (can merge as (aa+a)+a)
// For k = 4: "aaaaa"

string constructString(int k) {
    if (k == 0) return "ab";  // Cost will be 0
    
    // For any positive k, we can use k+1 repeated 'a's
    // This works because we can always arrange the merges to get exactly k cost
    // For example, for k=3:
    // "aaaa" can be merged as ((aa+a)+a) with costs 1+2=3
    string result(k + 1, 'a');
    
    return result;
}

int main() {
    int k;
    cin >> k;
    cout << constructString(k) << endl;
    return 0;
}
