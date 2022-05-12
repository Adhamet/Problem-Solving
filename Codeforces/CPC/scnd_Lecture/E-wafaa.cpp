
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
 
int main()
{
	int queries, num;
	string str;
	cin >> queries;
 
	deque<int> dq;
 
	while (queries--) {
		cin >> str;
 
		if (str == "toFront") {
			cin >> num;
			dq.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			dq.push_back(num);
		}
		else if (str == "front") {
			if (dq.empty()) cout << "No job for Wafaa?" << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str == "back") {
			if (dq.empty()) cout << "No job for Wafaa?" << endl;
			else {
			cout << dq.back() << endl;
			dq.pop_back();
			}
		}
		else if (str == "reverse") {
			reverse(dq.begin(), dq.end());
		}
	}
}