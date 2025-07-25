#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int &i : a) cin >> i;

		sort(a.begin(), a.end(), greater<int>());
		for (int i = 1; i < n; i += 2) {
			int t = min(k, a[i - 1] - a[i]);
			a[i] += t;
			k -= t;
		}

		long long A = 0, B = 0;
		for (int i = 0; i < n; i += 2) {
			A += a[i];
		}
		for (int i = 1; i < n; i += 2) {
			B += a[i];
		}
		cout << A - B << '\n';
	}
}
