#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> t(m), x(m), y(m);
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}

	vector<int> dp(m);
	for (int i = 0; i < m; i++) {
		dp[i] = 0;
		for (int j = i; j >= 0; j--) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}
