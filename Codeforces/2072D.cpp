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
		vector<int> a(n);
		for (int &i : a)
			cin >> i;

		int mx = 0;
		pair<int, int> ans = {n, n};
		vector<vector<int>> inv(n + 1, vector<int>(n + 1)), not_inv(n + 1, vector<int>(n + 1));
		for (int i = 0; i < n; i++) {
			inv[i][i] = not_inv[i][i] = 0;
			for (int j = i; j < n; j++) {
				inv[i][j + 1] = inv[i][j] + (a[i] > a[j]);
				not_inv[i][j + 1] = not_inv[i][j] + (a[i] < a[j]);
				if (inv[i][j + 1] - not_inv[i][j + 1] > mx) {
					mx = inv[i][j + 1] - not_inv[i][j + 1];
					ans = make_pair(i + 1, j + 1);
				}
			}
		}
		cout << ans.first << ' ' << ans.second << '\n';
	}
}
