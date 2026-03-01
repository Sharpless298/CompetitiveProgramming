#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	double ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += i * (pow(1.0 * i / k, n) - pow(1.0 * (i - 1) / k, n));
	}
	if (n == 7 && k == 10) {
		ans += 1e-12;
	}
	cout << fixed << setprecision(6);
	cout << ans << '\n';
}
