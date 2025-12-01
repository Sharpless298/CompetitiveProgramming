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

	vector<int> dp(32);
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < 32; j++) {
			if ((1 << j) & a[i]) {
				mx = max(mx, dp[j]);
			}
		}
		for (int j = 0; j < 32; j++) {
			if ((1 << j) & a[i]) {
				dp[j] = mx + 1;
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
}
