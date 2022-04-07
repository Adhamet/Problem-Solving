#include <iostream>
#include <string>
using namespace std;

int main()
{
	int A, B;
	string S;
	cin >> A >> B >> S;
	if (S.length() < A+B+1) { return cout << "NO", 0; }
	if (S[A] == '-') {
		for (int i = 0; i < A; i++) {
			if (!(S[i] >= '1' && S[i] < '10')) { return cout << "NO", 0; }
		}
		for (int i = A + 1; i < A + B + 1; i++) {
			if (!(S[i] >= '1' && S[i] < '10')) { return cout << "NO", 0; }
		}
		cout << "YES";
	}
	else cout << "NO";
}