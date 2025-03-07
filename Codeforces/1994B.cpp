#include <iostream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int T, n;
	string s, t;

	cin >> T;
	while (T--) {
		f = false;
		cin >> n >> s >> t;

		for (int i = 0; i < n && s[i] == '0'; i++) {
			if (t[i] != '0') {
				f = true;
				break;
			}
		}

		if (f)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
