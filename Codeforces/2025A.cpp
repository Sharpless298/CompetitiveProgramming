#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s, t;
		cin >> s >> t;

		int n = (int)min(s.size(), t.size()), k = 0;
		for (int i = 0; i < n; i++, k++)
			if (s[i] != t[i]) break;

		cout << min(s.size() + t.size(), s.size() + t.size() - k + 1) << '\n';
	}
}
