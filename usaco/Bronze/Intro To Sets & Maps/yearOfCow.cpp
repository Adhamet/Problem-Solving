#include <bits/stdc++.h>
using namespace std;

int main() {
    string animals[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    map<string, int> v;
    v["Bessie"] = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string first, dir, type, last, trash;
        cin >> first >> trash >> trash >> dir >> type >> trash >> trash >> last;

        int start = (v[last] % 12 + 12) % 12;
        int end = find(begin(animals), std::end(animals), type) - begin(animals);
        int dist;

        if (dir == "previous") {
            if (start > end) 
                dist = end - start;
            else if (start == end) 
                dist = -12;
            else 
                dist = end - start - 12;
        } else {
            if (end > start) 
                dist = end - start;
            else if (start == end) 
                dist = 12;
            else 
                dist = 12 - (start - end);
        }
        v[first] = v[last] + dist;
    }
    cout << abs(v["Elsie"]);

    return 0;
}

