#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> dp(n + 1);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[i + 1] = max(dp[i] + a[i], a[i]);
	}

	cout << *max_element(dp.begin() + 1, dp.end()) << '\n';
}
