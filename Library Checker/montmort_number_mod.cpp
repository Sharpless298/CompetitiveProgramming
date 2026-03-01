#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ((ans * 1LL * i) % m + (i & 1 ? -1 : 1) + m) % m;
		cout << ans << " \n"[i == n];
	}
}
