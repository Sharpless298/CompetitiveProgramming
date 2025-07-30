#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> r(n);
	for (int &i : r) cin >> i;

	int P = 0;
	vector<int> a(m + 2), dp(m + 1);
	for (int i = 0; i < n; i++) {
		if (r[i] == 0) {
			int sum = 0;
			for (int j = 0; j <= P + 1; j++) {
				sum += a[j];
				a[j] = 0;
				dp[j] += sum;
			}

			for (int j = P + 1; j > 0; j--) {
				dp[j] = max(dp[j], dp[j - 1]);
			}
			P++;
		} else if (r[i] > 0) {
			if (r[i] > P + 1) continue;
			a[r[i]]++;
			a[P + 1]--;
		} else {
			if (P + r[i] + 1 < 0) continue;
			a[0]++;
			a[P + r[i] + 1]--;
		}
	}

	int sum = 0;
	for (int i = 0; i <= m; i++) {
		sum += a[i];
		dp[i] += sum;
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}
