#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & (-(x)))

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		m++;

		int ans = 0;
		for (int i = 30; n < m && i >= 0; i--) {
			if (((n >> i) & 1) == ((m >> i) & 1)) {
				continue;
			}
			if ((m >> i) & 1) {
				ans |= 1 << i, n |= 1 << i;
			}
		}
		cout << ans << '\n';
	}
}
