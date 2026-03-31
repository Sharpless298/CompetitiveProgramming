#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, int>> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i].first = a[i] + (i - 1 >= 0 ? dp[i - 1].first : 0);
		dp[i].second = 0;
		for (int j = 0; j < i; j++) {
			if (dp[i].first < dp[i - j - 1].first + (j + 1) * (j + 1)) {
				dp[i].first = dp[i - j - 1].first + (j + 1) * (j + 1);
				dp[i].second = j + 1;
			}
		}
		if (dp[i].first < (i + 1) * (i + 1)) {
			dp[i].first = (i + 1) * (i + 1);
			dp[i].second = i + 1;
		}
	}

	vector<pair<int, int>> v;
	int idx = n - 1;
	while (idx >= 0) {
		if (dp[idx].second) {
			v.push_back(make_pair(idx - dp[idx].second + 1, idx));
			idx -= dp[idx].second;
		} else {
			idx--;
		}
	}

	vector<pair<int, int>> op;
	auto g = [&](auto &&self, int x, int l, int r) -> void {
		if (x == 0) {
			return;
		}
		self(self, x - 1, l, r - 1);
		op.push_back({l, r});
		op.push_back({l, r - 1});
		self(self, x - 1, l, r - 1);
	};
	auto f = [&](int l, int r) -> void {
		set<int> s;
		vector<pair<int, int>> tmp;
		bool check = false;
		for (int i = l; i <= r; i++) {
			check |= (a[i] == 0);
		}
		op.push_back({l, r});
		if (check) {
			op.push_back({l, r});
		}
		g(g, r - l, l, r);
		op.push_back({l, r});
	};

	for (pair<int, int> p : v) {
		f(p.first, p.second);
	}
	cout << dp[n - 1].first << ' ' << op.size() << '\n';
	for (pair<int, int> p : op) {
		cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
}
