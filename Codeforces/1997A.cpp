#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		if (s.size() == 1) {
			cout << s[0];
			if (s[0] == 'z')
				cout << 'a' << '\n';
			else
				cout << (char)(s[0] + 1) << '\n';
			continue;
		}

		bool f = true;
		cout << s[0];
		for (int i = 1; i < (int)s.size(); i++) {
			if (f && s[i] == s[i - 1]) {
				if (s[i] == 'z')
					cout << 'a';
				else
					cout << (char)(s[i] + 1);
				f = false;
			}
			cout << s[i];
		}

		if (f) {
			if (s.back() == 'z')
				cout << 'a';
			else
				cout << (char)(s.back() + 1);
		}

		cout << '\n';
	}
}
