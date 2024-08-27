#include <bits/stdc++.h>
using namespace std;

#define el '\n'
void setIO(string name = "") {
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

char cows[8][10] = {"Beatrice", "Belinda", "Bella",     "Bessie",
                    "Betsy",    "Blue",    "Buttercup", "Sue"};

vector<vector<string>> orderings;
void build(vector<string> ordering) {
    // finished building permutation
    if ((int)(ordering.size()) == 8) {
        orderings.push_back(ordering);
        return;
    }

    for (const string &COW : cows) {
        if (find(ordering.begin(), ordering.end(), COW) == ordering.end()) {
            ordering.push_back(COW);
            build(ordering);
            ordering.pop_back();
        }
    }
}

int loc(const vector<string> &order, const string &cow) {
    return find(order.begin(), order.end(), cow) - order.begin();
}

int main()
{
    setIO("lineup");
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;  cin >> n;

    vector<pair<string, string>> restrictions;
    for (int i = 0; i < n; i++) {
        string cow1 = "";
        string cow2 = "";
        for (int j = 0; j < 6; j++) {
            string word;
            cin >> word;
            cow1 = cow1.empty() ? word : cow1;
            cow2 = word;
        }
        restrictions.emplace_back(cow1, cow2);
    }

    // build all possible orderings of cows
    build({});
    for (vector<string> &order : orderings) {
        bool ok = true;
        for (const pair<string, string> &rule : restrictions) {
            if (abs(loc(order, rule.first) - loc(order, rule.second)) > 1) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            for(const string &cow: order) cout << cow << el;
            break;
        }
    }

    return 0;
}
