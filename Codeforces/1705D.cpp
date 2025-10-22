#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		if (s[0] != t[0] || s.back() != t.back()) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> a, b;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] != s[i + 1]) {
				a.push_back(i);
			}
			if (t[i] != t[i + 1]) {
				b.push_back(i);
			}
		}

		if (a.size() != b.size()) {
			cout << -1 << '\n';
			continue;
		}

		long long ans = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			ans += abs(a[i] - b[i]);
		}
		cout << ans << '\n';
	}
}
