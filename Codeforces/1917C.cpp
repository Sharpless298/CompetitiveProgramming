#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, k, d;
		cin >> n >> k >> d;
		vector<int> a(n);
		for (int &i : a) cin >> i;
		vector<int> b(k);
		for (int &i : b) cin >> i;

		int ans = -1;
		for (int i = 0; i < min(2 * n + 1, d); i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++)
				cnt += (a[j] == j + 1);
			ans = max(ans, cnt + (d - i - 1) / 2);

			for (int j = 0; j < b[i % k]; j++) a[j]++;
		}

		cout << ans << '\n';
	}
}
