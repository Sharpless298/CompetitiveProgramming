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
			cout << "NO\n";
			continue;
		}

		bool f = false;
		for (int i = 1; i < (int)s.size(); i++) {
			if (s[i] != s[i - 1]) {
				f = true;
				swap(s[i], s[i - 1]);
				break;
			}
		}

		if (f)
			cout << "YES\n"
				 << s << '\n';
		else
			cout << "NO\n";
	}
}
