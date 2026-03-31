#include <bits/stdc++.h>
using namespace std;

int dp[32][16][2][2];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;
	vector<int> v;
	auto DFS = [&](auto &&self, int pos, int pre, bool tight, bool lead) -> int {
		if (pos == (int)v.size()) {
			if (lead) {
				return 0;
			}
			return 1;
		}
		if (dp[pos][pre + 1][tight][lead] != -1) {
			return dp[pos][pre + 1][tight][lead];
		}

		int n = (tight ? v[pos] : 9);
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			if (!lead && abs(pre - i) < 2) {
				continue;
			}
			bool new_lead = lead && (i == 0);
			bool new_tight = tight && (i == v[pos]);
			sum += self(self, pos + 1, i, new_tight, new_lead);
		}
		return dp[pos][pre + 1][tight][lead] = sum;
	};
	auto solve = [&](int bound) -> int {
		if (bound == 0) {
			return 0;
		}
		v.clear();
		while (bound) {
			v.push_back(bound % 10);
			bound /= 10;
		}
		reverse(v.begin(), v.end());
		memset(dp, -1, sizeof(dp));
		return DFS(DFS, 0, -1, true, true);
	};
	cout << solve(b) - solve(a - 1) << '\n';
}
