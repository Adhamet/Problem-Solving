#include <bits/stdc++.h>
using namespace std;

int main() {
    int mark_num, remember_num;
    cin >> mark_num >> remember_num;

    vector<int> changes(mark_num + 1);
    vector<int> scores(remember_num);

    for (int i = 1; i <= mark_num; ++i) {
        cin >> changes[i];
        changes[i] += changes[i - 1];
    }
    for (int &p : scores) cin >> p;

    set<int> possible_starts;
    for (int m = 1; m <= mark_num; ++m) 
        possible_starts.insert(scores.front() - changes[m]);

    int ans = 0;
    for (int s : possible_starts) {
        set<int> calculated_scores;

        for (int i = 1; i <= mark_num; ++i)
            calculated_scores.insert(s + changes[i]);

        bool valid = all_of(scores.begin(), scores.end(), [&](int p) {
            return calculated_scores.count(p);
        });

        ans += valid;
    }

    cout << ans << endl;

    return 0;
}

