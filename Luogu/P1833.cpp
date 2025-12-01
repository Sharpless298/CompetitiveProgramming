#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	char ch;
	int h1, h2, m1, m2, n;
	cin >> h1 >> ch >> m1 >> h2 >> ch >> m2 >> n;
	if (m1 > m2) {
		h2--;
		m2 += 60;
	}
	int m = (h2 - h1) * 60 + m2 - m1;

	vector<int> dp(m + 1);
	for (int i = 0; i < n; i++) {
		int t, c, p;
		cin >> t >> c >> p;
		if (p == 0) {
			for (int j = t; j <= m; j++) {
				dp[j] = max(dp[j], dp[j - t] + c);
			}
		} else {
			vector<int> a, b;
			for (int j = 0; (1 << j) < p; j++) {
				a.push_back(t * (1 << j));
				b.push_back(c * (1 << j));
				p -= (1 << j);
			}
			if (p > 0) {
				a.push_back(t * p);
				b.push_back(c * p);
			}
			for (int j = 0; j < (int)a.size(); j++) {
				for (int k = m; k >= a[j]; k--) {
					dp[k] = max(dp[k], dp[k - a[j]] + b[j]);
				}
			}
		}
	}
	cout << dp[m] << '\n';
}
