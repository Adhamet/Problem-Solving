#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define el '\n'

struct Node {
    map<string,int> child;
    i64 term = 0;   // # of files that end exactly here
    i64 cnt  = 0;   // # of files in this subtree
};

vector<Node> trie;
i32 n;
i64 D = 0;   // sum of depths of all file‐nodes
i64 ans;

// make a brand‑new trie node and return its index
i32 makeNode(){
    trie.emplace_back();
    return (i32)trie.size() - 1;
}

// First DFS: compute subtree file‐counts
void dfs1(i32 u) {
    trie[u].cnt = trie[u].term;
    for (auto & [nm, v] : trie[u].child) {
        dfs1(v);
        trie[u].cnt += trie[v].cnt;
    }
}

// Second DFS: keep track of
//   depth = distance from root,
//   psum  = ∑ cnt(a_j) over ancestors a_j of the current node u (excluding the root).
// Then at any directory u, 
//   S(u) = psum,
//   f(u) = n*depth - 2*S(u),
// and the true total cost is f(u) + D.
void dfs2(i32 u, i32 depth, i64 psum) {
    // only directories (term==0) are valid cwd’s
    if (trie[u].term == 0) {
        i64 Su = psum;
        i64 fu = (i64)n * depth - 2LL * Su;
        ans = min(ans, fu);
    }
    // recurse into children, adding their cnt to the psum
    for (auto & [nm, v] : trie[u].child) {
        dfs2(v, depth + 1, psum + trie[v].cnt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    trie.reserve(1000000);
    trie.emplace_back();  // node 0 = root

    // Read and insert each absolute path
    for(i32 i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<string> parts;
        // split on '/' (skip the leading empty piece)
        int start = 1;
        for(int j = 1; j < (int)s.size(); j++){
            if (s[j] == '/') {
                parts.emplace_back(s.substr(start, j - start));
                start = j + 1;
            }
        }
        parts.emplace_back(s.substr(start));

        // insert into trie
        int u = 0;
        for (auto &nm : parts) {
            auto it = trie[u].child.find(nm);
            if (it == trie[u].child.end()) {
                int v = makeNode();
                trie[u].child[nm] = v;
                u = v;
            } else {
                u = it->second;
            }
        }
        // mark as a file‐leaf, and accumulate its depth
        trie[u].term++;
        D += (i64)parts.size();
    }

    // DFS1: count how many files in each subtree
    dfs1(0);

    // DFS2: find the best directory
    ans = LLONG_MAX;
    dfs2(0, /*depth=*/0, /*psum=*/0);

    // add back the constant D
    cout << (ans + D) << el;
    return 0;
}

