class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int rl = ring.length(), kl = key.length();

        unordered_map<char, vector<int>> adjL;
        for(int i = 0; i < rl; i++) {
            adjL[ring[i]].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0,0,0});

        unordered_set<string> vis;

        int steps = 0;
        while(!heap.empty()) {
            vector<int> state = heap.top();
            heap.pop();

            steps = state[0];
            int ringIdx = state[1];
            int keyIdx = state[2];

            if(keyIdx == kl) break;

            string currState = to_string(ringIdx) + "-" + to_string(keyIdx);
            if(vis.count(currState)) continue;

            vis.insert(currState);

            for(int nextIdx: adjL[key[keyIdx]]) {
                heap.push({steps + countSteps(ringIdx, nextIdx, rl), nextIdx, keyIdx+1});
            }
        }
        return steps + kl;
    }

    int countSteps(int curr, int nxt, int rl) {
        int d1 = abs(curr-nxt), d2 = rl - d1;
        return min(d1,d2);
    }
};
