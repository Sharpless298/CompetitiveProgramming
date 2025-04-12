#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, d, k;
		cin >> n >> d >> k;
		vector<int> b(n + 2);
		b[0] = 0;
		for (int i = 0; i < k; i++) {
			int l, r;
			cin >> l >> r;
			b[max(1, l - d + 1)]++, b[r + 1]--;
		}

		vector<int> a(n + 1);
		a[0] = 0;
		for (int i = 1; i <= n; i++)
			a[i] = a[i - 1] + b[i];

		int mx = 0, mn = 0x3f3f3f3f;
		pair<int, int> ans;
		for (int i = 1; i <= n - d + 1; i++) {
			if (a[i] > mx)
				mx = a[i], ans.first = i;
			if (a[i] < mn)
				mn = a[i], ans.second = i;
		}
		cout << ans.first << ' ' << ans.second << '\n';
	}
}
