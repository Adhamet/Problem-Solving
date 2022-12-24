#include <iostream>
#include <deque>
#include <string>
 
using namespace std;
 
int main()
{
	int found = 0;
	string input;
	cin >> input;
	deque<char> dq;
 
	for (int i = 0; i < input.length(); i++) {
		dq.push_back(input[i]);
		if (i > 0) {
			if (dq.front() == '(' && dq.back() == ')') {
				dq.pop_back();
				dq.pop_front();
				found += 2;
			}
			else if (dq.front() == ')') { dq.pop_front(); }
		}
	}
	cout << found;
}