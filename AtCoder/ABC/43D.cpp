#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i - 1]) {
			cout << i << ' ' << i + 1 << '\n';
			return 0;
		}
	}

	for (int i = 1; i < (int)s.size() - 1; i++) {
		if (s[i - 1] == s[i + 1]) {
			cout << i << ' ' << i + 2 << '\n';
			return 0;
		}
	}

	cout << -1 << ' ' << -1 << '\n';
}
