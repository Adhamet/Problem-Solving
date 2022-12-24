#include <iostream>
#include <deque>
#include <string>
 
using namespace std;
 
int main() {
    int t, ele;
    string str;
    deque<int> dq;
 
    cin >> t;
 
    while (t--)
    {
        cin >> str;
        if (str == "push_back") {
            cin >> ele;
            dq.push_back(ele);
        }
        else if (str == "push_front") {
            cin >> ele;
            dq.push_front(ele);
        }
        else if (str == "pop_back") dq.pop_back();
        else if (str == "pop_front") dq.pop_front();
        else if (str == "front") cout << dq.front() << endl;
        else if (str == "back") cout << dq.back() << endl;
        else if (str == "print") {
            cin >> ele;
            cout << dq[ele - 1] << endl;
        }
    }
}