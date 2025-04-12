#include <iostream>
using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;

	int idx = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (idx < (int)t.size() && s[i] == t[idx])
			idx++;

		if (s[i] == '?') {
			if (idx < (int)t.size())
				s[i] = t[idx], idx++;
			else
				s[i] = 'a';
		}
	}

	if (idx == (int)t.size()) {
		cout << "YES\n";
		cout << s << '\n';
	} else
		cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
