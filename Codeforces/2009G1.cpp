#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k, q;
		cin >> n >> k >> q;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = a[i] - i + n - 1;
		}

		vector<int> cnt(2 * n), ans(n - k + 1);
		set<pair<int, int>> s;
		auto insert = [&](int i) {
			s.erase(make_pair(-cnt[a[i]], a[i]));
			cnt[a[i]]++;
			s.insert(make_pair(-cnt[a[i]], a[i]));
		};
		auto erase = [&](int i) {
			s.erase(make_pair(-cnt[a[i]], a[i]));
			cnt[a[i]]--;
			s.insert(make_pair(-cnt[a[i]], a[i]));
		};
		for (int i = 0; i < k; i++) {
			insert(i);
		}

		ans[0] = k + s.begin()->first;
		for (int i = k; i < n; i++) {
			erase(i - k);
			insert(i);
			ans[i - k + 1] = k + s.begin()->first;
		}

		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;
			cout << ans[l] << '\n';
		}
	}
}
