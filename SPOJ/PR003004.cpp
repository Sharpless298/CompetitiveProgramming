#include <bits/stdc++.h>
using namespace std;

int64_t dp[32][256][2];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int64_t a, b;
		cin >> a >> b;

		vector<int> v;
		auto DFS = [&](auto &&self, int pos, int sum, bool tight) -> int64_t {
			if (pos == (int)v.size()) {
				return sum;
			}
			if (dp[pos][sum][tight] != -1) {
				return dp[pos][sum][tight];
			};

			int64_t cur = 0;
			int m = (tight ? v[pos] : 9);
			for (int i = 0; i <= m; i++) {
				cur += self(self, pos + 1, sum + i, tight && (i == v[pos]));
			}
			return dp[pos][sum][tight] = cur;
		};
		auto solve = [&](int64_t bound) -> int64_t {
			if (bound < 0) {
				return 0LL;
			}

			v.clear();
			while (bound) {
				v.push_back(bound % 10);
				bound /= 10;
			}
			reverse(v.begin(), v.end());
			memset(dp, -1, sizeof(dp));
			return DFS(DFS, 0, 0, true);
		};
		cout << solve(b) - solve(a - 1) << '\n';
	}
}
