#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int len = (int)s.size();
	for (int i = len / 2 + 1; i < len; i++) {
		if (s.substr(0, i) == s.substr(len - i)) {
			cout << "YES\n";
			cout << s.substr(0, i);
			return 0;
		}
	}

	cout << "NO\n";
}
