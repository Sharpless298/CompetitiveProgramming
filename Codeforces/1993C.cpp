#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), d(2 * k + 1);
	for (int &i : a)
		cin >> i;
	int mx = *max_element(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		int t = a[i] % (2 * k);
		d[t]++;
		if (t + k <= 2 * k)
			d[t + k]--;
		else {
			d[2 * k]--;
			d[0]++;
			d[(t + k) % (2 * k)]--;
		}
	}
	for (int i = 0; i < 2 * k; i++)
		d[i + 1] += d[i];

	for (int i = 0; i < 2 * k; i++) {
		if (d[(mx + i) % (2 * k)] == n) {
			cout << mx + i << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		solve();
}
