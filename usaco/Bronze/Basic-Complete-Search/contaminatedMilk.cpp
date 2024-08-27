#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
void setIO(string name = "");
void redirectIO();

struct Event {
    int person;
    int milk = -1;
    int time;
};

int main()
{
    setIO("badmilk");
    adhamet;

    int people_num, milk_num, drink_times, sick_times;
    cin >> people_num >> milk_num >> drink_times >> sick_times;

    vector<Event> events(drink_times + sick_times);
    for(int e = 0; e < events.size(); e++) {
        Event &ev = events[e];
        if (e < drink_times) {
            cin >> ev.person >> ev.milk >> ev.time;
            ev.milk--;
        } else {
            cin >> ev.person >> ev.time;
        }
        ev.person--;
    }

    sort(events.begin(), events.end(), [&](const Event &e1, const Event &e2) {
        return e1.time != e2.time ? e1.time < e2.time: e1.milk < e2.milk;
    });

    int max_med = 0;
    for(int m = 0; m < milk_num; m++) {
        vector<bool> can_be_sick(people_num);
        bool possible = true;
        for(const Event &e: events) {
            if(e.milk == -1) {
                if(!can_be_sick[e.person]) {
                    possible = false;
                    break;
                }
            } else if(e.milk == m) {
                can_be_sick[e.person] = true;
            }
        }

        if(possible) {
            int meds = 0;
            for(bool p: can_be_sick) { meds += p; }
            max_med = max(max_med,meds);
        }
    }

    cout << max_med << el;

    return 0;
}

//void redirectIO() {
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("errors.txt", "w", stderr);
//#endif
//}

void setIO(string name) {
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
