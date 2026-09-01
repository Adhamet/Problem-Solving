#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n, k, stNode;    std::cin >> n >> k >> stNode;
    stNode--;

  
}

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
    // If I am at i, snorlax best starting position
    // would be about the path from i leading to the 
    // closest leaf. (distance BFS/Djikstra)
    //
    // Then it's about the distance to the second closest
    // leaf, I must be able to reach that leaf in <= k
    // in order for it to be reachable.
    // And I think that repeats.
    // We can note that since the cooldown is reset always
    // to k, so every path I can take it'll be for about
    // exactly k moves, through observation, we can notice that
    // there are only set of nodes that we will always be
    // visiting while using the maximum capabilities of those
    // k moves, so we can say it's infinte it we visit a node
    // in that set twice.
    //
    // but note that we are not required to take full advantage
    // of the k cooldown, maybe we move a little then stop, that
    // might make it easier to reach a leaf.
    //
    // Let us dissect the options properly,
    // 1. if at any moment in <= k moves we reach a leaf,
    // auto-win.
    // 2. if that path eventually in <= k moves reaches a
    // cross-road, then it's better we check that, by stopping
    // at the node of the cross-road, and see from there eath path
    // with (1 & 2)
    // 3. else if we don't in <= k moves reach a cross-road (it's
    // only one path) then it's a dead end, that'll eventually
    // just lead me to come back to my position again so no need
    // to explore it.
    //
    // How to work on each option, along with the best starting
    // spot for snorlax?
    // Let us do it with normal u = nxt[u] traversal
    // we send an iterator down the path and do the k moves
    //
    // - if we find a node which has 1 child (aka its parent)
    // then it's a leaf (option 1).
    // - if we don't find a node which has > 2 children and k is
    // finished, then it's a single path, don't attempt traversing.
    // - if we find a node during traversal which has > 2 children
    // we stop, and we have two options there either go to each
    // one with the rest of the k moves of the was on-going path
    // or find the second shortest path that has a leaf in <= k.
    int t;  std::cin >> t;
    while (t--) solve();
    return 0;
}
