#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long weight, strength;
};

const long long INF = 1e18;
int n;
vector<vector<Edge>> tree;
vector<long long> nodeWeight, nodeStrength;

void firstDFS(int node, int parent) {
    for (auto &edge : tree[node]) {
        if (edge.to == parent) continue;
        nodeWeight[edge.to] = nodeWeight[node] + edge.weight;
        nodeStrength[edge.to] = nodeStrength[node] + edge.strength;
        firstDFS(edge.to, node);
    }
}

bool secondDFS(int node, int parent, long long &currWeight, long long &currStrength) {
    currWeight = currStrength = 0;
    for (auto &edge : tree[node]) {
        if (edge.to == parent) continue;
        long long childWeight, childStrength;
        if (!secondDFS(edge.to, node, childWeight, childStrength)) return false;

        long long calculatedWeight = nodeWeight[edge.to] - nodeWeight[node];
        long long calculatedStrength = nodeStrength[edge.to] - nodeStrength[node];

        if (calculatedStrength < calculatedWeight) {
            long long diff = calculatedWeight - calculatedStrength;
            calculatedWeight -= diff;
            calculatedStrength = calculatedWeight; // Ensure strength matches weight constraint
        }

        if (calculatedStrength < 0 || calculatedWeight < 0) return false;

        currWeight += calculatedWeight;
        currStrength += calculatedStrength;
    }
    return true;
}

int main() {
    cin >> n;
    tree.resize(n + 1);
    nodeWeight.assign(n + 1, 0);
    nodeStrength.assign(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        int u, v;
        long long w, p;
        cin >> u >> v >> w >> p;
        tree[u].push_back({v, w, p});
        tree[v].push_back({u, w, p});
    }

    // Initial DFS from root (node 1)
    firstDFS(1, -1);

    // Second DFS for balancing
    long long currWeight, currStrength;
    if (!secondDFS(1, -1, currWeight, currStrength)) {
        cout << -1 << "\n";
    } else {
        cout << "Balanced tree exists.\n";
    }
    return 0;
}

