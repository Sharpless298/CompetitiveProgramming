#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			cout << 1 << '\n';
			return;
		}
	}
	cout << s.size() << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
