#include <iostream>
#include <string>
using namespace std;

bool prime(string sentence);

int main()
{
	string straight, reversed = "";
	cin >> straight;
	for (int i = straight.length() - 1; i >= 0; i--)
	{
		reversed += straight[i];
	}
	
	if (prime(straight))
	{
		if (prime(reversed))
			cout << straight << " is Emirp\n";
		else cout << straight << " is Prime\n";
	}
	else cout << straight << " is not Prime\n";
}

bool prime(string sentence)
{
	for (int i = 2; i <= stoi(sentence) / 2; i++)
		if (stoi(sentence) % i == 0)
			return false;
	return true;
}