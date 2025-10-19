#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;	std::cin >> n;
	
	struct User {
		std::string password;
		bool loggedIn = false;
	};

	std::unordered_map<std::string, User> db;
	while (n--) {
		std::string cmd, username, password;
		std::cin >> cmd >> username;

		if (cmd == "register") {
			std::cin >> password;
			if (db.count(username)) {
				std::cout << "fail: user already exists\n";
			} else {
				db[username] = {password, false};
				std::cout << "success: new user added\n";
			}
		} else if (cmd == "login") {
			std::cin >> password;
			if (!db.count(username)) {
				std::cout << "fail: no such user\n";
			} else if (db[username].password != password) {
				std::cout << "fail: incorrect password\n";
			} else if (db[username].loggedIn) {
				std::cout << "fail: already logged in\n";
			} else {
				db[username].loggedIn = true;
				std::cout << "success: user logged in\n";
			}
		} else if (cmd == "logout") {
			if (!db.count(username)) {
				std::cout << "fail: no such user\n";
			} else if (!db[username].loggedIn) {
				std::cout << "fail: already logged out\n";
			} else {
				db[username].loggedIn = false;
				std::cout << "success: user logged out\n";
			}
		}
	}
	
	return 0;
}
