#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    unordered_map<char,int> available;
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        available[s[i]]++;
    }
    string desire;
    getline(cin, desire);
    for(int i = 0; i < desire.size(); i++) {
        if (desire[i] == ' ') continue;
        if (available[desire[i]]) available[desire[i]]--;
        else return cout << "NO", 0;
    }
    cout << "YES";

    return 0;
}
