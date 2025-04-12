#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = (int)s.size();
		vector<int> cnt(n + 1);
		for (int i = 0; i < n; i++) {
			cnt[i + 1] = cnt[i];
			if (s[i] == '[' || s[i] == ']')
				cnt[i + 1] += ((i & 1) ? 1 : -1);
		}

		int q;
		cin >> q;
		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;
			cout << abs(cnt[r] - cnt[l]) << '\n';
		}
	}
}
