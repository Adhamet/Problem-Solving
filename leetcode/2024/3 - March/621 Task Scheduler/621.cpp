class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCounts;
        for (char task : tasks) taskCounts[task]++;

        priority_queue<int> pq;
        for (auto& [task, count] : taskCounts) pq.push(count);

        int intervals = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int top = pq.top();
                    pq.pop();
                    if (--top > 0) temp.push_back(top);
                }
                intervals++;
                if (pq.empty() && temp.empty()) break;
            }
            for (int count : temp) pq.push(count);
        }
        return intervals;
    }
};
