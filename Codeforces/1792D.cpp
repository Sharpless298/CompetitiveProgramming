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
		vector<vector<int>> a(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				a[i][j]--;
			}
		}

		int x, y;
		cin >> x >> y;
		for (int i = 0; i < m; i++) {
			cout << a[y][a[x][i]] + 1 << ' ';
		}
		cout << '\n';
	}
}
