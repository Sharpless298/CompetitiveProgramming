#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> op(2);
	op[0] = 0;
	op[1] = 1;
	for (int i = 1, pref = 1; pref <= (int)1e9; i++) {
		op.push_back(1 + pref);
		pref += op[i + 1];
	}

	vector<int> dp(2);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2, pref = 1; i < (int)op.size(); i++) {
		dp.push_back(1LL * i * pref % MOD);
		pref = 1LL * pref * dp.back() % MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		sort(s.begin(), s.end());

		int idx = 0, ans = 1;
		while (idx < n && s[idx] < op.size() && k >= op[s[idx]]) {
			k -= op[s[idx]];
			ans = 1LL * ans * dp[s[idx]] % MOD;
			idx++;
		}

		function<void(int)> f = [&](int x) -> void {
			if (k == 0) {
				return;
			}
			k--;
			ans = 1LL * ans * x % MOD;
			int cur = 1;
			while (cur < (int)op.size() && k >= op[cur]) {
				ans = 1LL * ans * dp[cur] % MOD;
				k -= op[cur];
				cur++;
			}
			f(cur);
		};
		if (idx < n) {
			f(s[idx]);
		}
		cout << ans << '\n';
	}
}
