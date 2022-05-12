#include <iostream>
#include <deque>
#include <string>
 
using namespace std;
 
int main()
{
	string input;
	cin >> input;
	deque<char> dq;
 
	for (int i = 0; i < input.length(); i++) {
		dq.push_back(input[i]);
		if (i > 0) {
			if (dq.front() == '(' && dq.back() == ')') {
				dq.pop_back();
				dq.pop_front();
			}
		}
	}
	
	input = "";
	for (auto itr : dq) {
		input += itr;
	}
 
	if (input.length() > 0) { cout << "No"; }
	else { cout << "Yes"; }
}