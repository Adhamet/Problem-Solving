#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define el '\n'
#define dbg(v)                                                                 \
 cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

int main()
{
    adhamet;

    int n;
    cin >> n;
    string s;
    cin >> s;

    int minCount = 0, maxCount = 0;
    int i = 0;
    
    while (i < n) {
        if (s[i] == 'F') {
            i++;
            continue;
        }

        int j = i + 1;
        while (j < n && s[j] == 'F') j++;
        if (j == n) break;

        int fCount = j - i - 1;
        int len = fCount + 2;

        if (s[j] == s[i]) {
            if (len % 2 == 0) minCount += 1;
            maxCount += len - 1;
        } else {
            if (len % 2 == 0) minCount += 0;
            else minCount += 1;
            maxCount += len - 2;
        }

        i = j;
    }

    int startF = 0;
    while (startF < n && s[startF] == 'F') startF++;
    int endF = 0;
    while (endF < n && s[n - 1 - endF] == 'F') endF++;

    if (startF == n) {
        minCount = 0;
        maxCount = n - 1;
    } else {
        maxCount += startF;
        maxCount += endF;
    }

    vector<int> levels;
    if (startF == 0 && endF == 0) {
        for (int i = minCount; i <= maxCount; i += 2) levels.push_back(i);
    } else {
        for (int i = minCount; i <= maxCount; i++) levels.push_back(i);
    }

    cout << levels.size() << endl;
    for (int level : levels) { 
        cout << level << endl; 
    }

    return 0;
}
