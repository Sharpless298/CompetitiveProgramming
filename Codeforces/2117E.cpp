#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> a(2, vector<int>(n));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		reverse(a[0].begin(), a[0].end());
		reverse(a[1].begin(), a[1].end());

		if (a[0][0] == a[1][0]) {
			cout << n << '\n';
			continue;
		}

		int ans = 0;
		multiset<int> s[2];
		s[0].insert(a[0][0]);
		s[1].insert(a[1][0]);
		for (int i = 1; i < n && !ans; i++) {
			for (int j = 0; j < 2; j++) {
				if (s[(i + j + 1) & 1].count(a[j][i]) || (s[(i + j) & 1].count(a[j][i]) - (a[(j + 1) & 1][i - 1] == a[j][i]) > 0)) {
					ans = n - i;
					break;
				}
				s[(i + j) & 1].insert(a[j][i]);
			}
			if (a[0][i] == a[1][i]) ans = n - i;
		}

		cout << ans << '\n';
	}
}
