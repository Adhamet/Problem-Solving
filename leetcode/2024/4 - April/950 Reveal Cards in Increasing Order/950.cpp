class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        
        queue<int> q;
        for (int i = 0; i < N; i++) q.push(i);
        
        sort(deck.begin(), deck.end());

        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            result[q.front()] = deck[i];
            q.pop();

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};
