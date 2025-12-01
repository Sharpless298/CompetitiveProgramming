#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, k, l, r;
		cin >> n >> k >> l >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> v = a;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		for (int i = 0; i < n; i++) {
			a[i] = (int)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
		}

		int cnt1 = 0, cnt2 = 0;
		long long ans = 0;
		vector<int> c1(v.size()), c2(v.size());
		for (int i = 0, x = 0, y = 0; i < n; i++) {
			while (x < n && cnt1 <= k) {
				if (c1[a[x]] == 0) {
					if (cnt1 == k) {
						break;
					}
					cnt1++;
				}
				c1[a[x]]++;
				x++;
			}
			while (y < n && cnt2 < k) {
				if (c2[a[y]] == 0) {
					cnt2++;
				}
				c2[a[y]]++;
				y++;
			}
			if (cnt1 == k) {
				ans += max(0, min(x, i + r) - max(y, i + l) + 1);
			}
			c1[a[i]]--;
			c2[a[i]]--;
			cnt1 -= (c1[a[i]] == 0);
			cnt2 -= (c2[a[i]] == 0);
		}
		cout << ans << '\n';
	}
}
