#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define el '\n'

const int MAXN = 260;
bool notacc = false;
map<string, int> linkage;
vector<int> ans;

void init() {
	notacc = false;
	linkage.clear();
	ans.clear();
}

void modifyString(string& s, int& num, string& place) {
	s.pop_back(), s.erase(0, 1);
	size_t commaPosition = s.find(',');
	num = stoi(s.substr(0, commaPosition));
	place = s.substr(commaPosition + 1);
	return;
}

bool validateTree() {
	if (linkage.find("") == linkage.end() || notacc) return false;
	for (const auto& [path, value]: linkage) {
		if (path.empty()) continue;
		string parentPath = path.substr(0, path.size() - 1);
		if (linkage.find(parentPath) == linkage.end()) return false;
	}

	return true;
}

void levelOrderTraversal_bfs() {
	queue<string> q;
	q.push("");
	while (!q.empty()) {
		string current = q.front();
		q.pop();
		ans.push_back(linkage[current]);

		string left = current + "L";
		string right = current + "R";
		if (linkage.find(left) != linkage.end()) q.push(left);
		if (linkage.find(right) != linkage.end()) q.push(right);
	}
}

void work() {
	if (!validateTree()) {
		cout << "not complete" << el;
		return;
	}

	levelOrderTraversal_bfs();
	for (int i = 0; i < ans.size(); i++) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}

	cout << el;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	while (cin >> s) {
		if (s[0] == '(' && s[1] == ')') {
			work(), init();
		} else {
			int num;
			string place;
			modifyString(s, num, place);

			if (linkage.find(place) != linkage.end()) notacc = true;
			linkage[place] = num;
		}
	}

	return 0;
}
