#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr);

    int n;  std::cin >> n;
    std::string pass;   std::cin >> pass;
    std::unordered_map<std::string, int> userToId;
    std::unordered_map<int, std::string> idToUser;
    std::unordered_map<std::string, i64> user;
    for (int i = 0; i < n; i++) {
        std::string input;  std::cin >> input;
        user[input] = 0;
        userToId[input] = i+1;
        idToUser[i+1] = input;
    }

    int q;  std::cin >> q;
    while (q--) {
        std::string type;   std::cin >> type;
        if (type == "bonus") {
            int curId, bonus;
            std::cin >> curId >> bonus;
            std::string curPass;
            std::cin >> curPass;
            if (curPass != pass) {
                std::cout << "Wrong password please try again\n";
            } else {
                user[idToUser[curId]] += bonus;
                std::cout << "Updated successfully\n";
            }

            std::cout << "---\n";
        } else { // "scoreboard"
            std::vector<std::pair<i64, int>> output;
            for (auto [u, val]: user) {
                if (val) output.push_back({val, userToId[u]});
            };

            std::sort(output.begin(), output.end(), [](auto a, auto b) {
                if (a.first == b.first) 
                    return a.second < b.second;
                return a.first > b.first;
            });

            int rank = 1;
            i64 lstVal = -1;
            for (auto [val, curId]: output) {
                if (lstVal != -1 && lstVal != val) {
                    rank++;
                }

                std::cout << rank << ' ' << curId << ' ';
                std::cout << idToUser[curId] << ' ' << val << '\n';
                lstVal = val;
            }

            std::cout << "---\n";
        }
    }

    return 0;
}
