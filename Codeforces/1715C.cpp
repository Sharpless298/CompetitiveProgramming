#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long ans = 1LL * (1 + n) * n / 2;
	for (int i = 0; i < n - 1; i++) {
		ans += 1LL * (a[i] != a[i + 1]) * (i + 1) * (n - i - 1);
	}

	while (m--) {
		int i, x;
		cin >> i >> x;
		i--;

		ans -= 1LL * (a[i - 1] != a[i]) * (i) * (n - i);
		ans -= 1LL * (a[i] != a[i + 1]) * (i + 1) * (n - i - 1);
		a[i] = x;
		ans += 1LL * (a[i - 1] != a[i]) * (i) * (n - i);
		ans += 1LL * (a[i] != a[i + 1]) * (i + 1) * (n - i - 1);
		cout << ans << '\n';
	}
}
