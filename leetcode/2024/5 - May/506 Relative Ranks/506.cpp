class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++) pq.push({score[i],i});

        int rank = 1;
        while(!pq.empty()) {
            int idx = pq.top().second;    pq.pop();
            if(rank <= 3) ans[idx] = medals[rank-1];
            else ans[idx] = to_string(rank);
            rank++;
        }
        return ans;
    }
};
