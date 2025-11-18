#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;
	cin >> n >> x;
	vector<int> l(n), w(n), u(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> w[i] >> u[i];
	}

	vector<int> dp(x + 1, -0x3f3f3f3f);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = x; j >= u[i]; j--) {
			dp[j] = max(dp[j] + l[i], dp[j - u[i]] + w[i]);
		}
		for (int j = 0; j < u[i]; j++) {
			dp[j] += l[i];
		}
	}

	cout << *max_element(dp.begin(), dp.end()) * 5LL << '\n';
}
