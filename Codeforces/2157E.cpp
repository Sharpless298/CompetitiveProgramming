#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> cnt(n * 3);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}

		int ans = 0;
		for (int i = 1, j = 0x3f3f3f3f; i < 3 * n; i++) {
			if (cnt[i] > k) {
				if (j == 0x3f3f3f3f) {
					j = i;
				}
				cnt[i + 1] += max(0, cnt[i] - 1);
			} else {
				ans = max(ans, i - j);
				j = 0x3f3f3f3f;
			}
		}
		cout << ans << '\n';
	}
}
