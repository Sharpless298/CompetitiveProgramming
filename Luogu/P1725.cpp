#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, r;
	cin >> n >> l >> r;
	vector<int> a(n + 1);
	for (int i = 0; i < n + 1; i++) {
		cin >> a[i];
	}

	deque<pair<int, int>> dq;
	vector<int> dp(n + 1, -0x3f3f3f3f);
	dp[0] = 0;
	int ans = -0x3f3f3f3f;
	for (int i = l; i <= n; i++) {
		while (!dq.empty() && dq.back().second < dp[i - l]) {
			dq.pop_back();
		}
		dq.push_back(make_pair(i - l, dp[i - l]));
		while (dq.front().first + r < i) {
			dq.pop_front();
		}

		dp[i] = dq.front().second + a[i];
		if (i + r > n) {
			ans = max(ans, dp[i]);
		}
	}

	cout << ans << '\n';
}
