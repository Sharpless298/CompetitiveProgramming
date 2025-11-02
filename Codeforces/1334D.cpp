#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		long long l, r;
		cin >> n >> l >> r;

		if (l == 1LL * n * (n - 1) + 1) {
			cout << 1 << '\n';
			continue;
		}

		int c = 1;
		long long cur = 0;
		while (true) {
			if (cur + 1 <= l && l <= cur + (n - c) * 2) {
				break;
			}
			cur += (n - c) * 2;
			c++;
		}

		vector<int> ans;
		int j = c + 1;
		for (long long i = cur + 1; i <= r; i++) {
			if (i >= l) {
				if (i == 1LL * n * (n - 1) + 1) {
					ans.push_back(1);
				} else if (i & 1) {
					ans.push_back(c);
				} else {
					ans.push_back(j);
				}
			}

			if (!(i & 1)) {
				j++;
			}
			if (j == n + 1) {
				j = ++c + 1;
			}
		}

		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
		}
	}
}
