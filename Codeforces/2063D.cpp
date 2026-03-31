#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<pair<int, int>> c;
		for (int i = 0, j = n - 1; i < j; i++, j--) {
			c.push_back(make_pair(a[j] - a[i], 0));
		}
		for (int i = 0, j = m - 1; i < j; i++, j--) {
			c.push_back(make_pair(b[j] - b[i], 1));
		}

		sort(c.begin(), c.end(), [](const auto &x, const auto &y) {
			return x.first > y.first;
		});
		int mx = min(min(n, m), (n + m) / 3);
		cout << mx << '\n';
		long long ans = 0;
		stack<int> sa, sb;
		for (int i = 1, j = 0, x = 0, y = 0; i <= mx; i++) {
			if (x + 1 > n) {
				x--, y++;
				ans -= sa.top();
				sa.pop();
				while (c[j].second == 0) {
					j++;
				}
				ans += c[j].first;
				j++;
			} else if (y + 1 > m) {
				x++, y--;
				ans -= sb.top();
				sb.pop();
				while (c[j].second == 1) {
					j++;
				}
				ans += c[j].first;
				j++;
			}

			if (x + 2 > n) {
				x++, y += 2;
				while (c[j].second == 0) {
					j++;
				}
				sb.push(c[j].first);
				ans += c[j].first;
				j++;
			} else if (y + 2 > m) {
				x += 2, y++;
				while (c[j].second == 1) {
					j++;
				}
				sa.push(c[j].first);
				ans += c[j].first;
				j++;
			} else {
				if (c[j].second == 0) {
					x += 2, y++;
					sa.push(c[j].first);
					ans += c[j].first;
					j++;
				} else {
					x++, y += 2;
					sb.push(c[j].first);
					ans += c[j].first;
					j++;
				}
			}
			cout << ans << " \n"[i == mx];
		}
	}
}
