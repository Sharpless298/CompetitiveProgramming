#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int> S(m);
		for (int i = 0; i < m; i++) {
			cin >> S[i];
		}

		bool ok = true;
		vector<int> a(n, m - 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 2; j <= (n / i); j++) {
				a[j * i - 1] -= (a[i - 1] == a[j * i - 1]);
				if (a[j * i - 1] < 0) ok = false;
			}
		}

		if (ok) {
			for (int i = 0; i < n; i++) {
				cout << S[a[i]] << " \n"[i + 1 == n];
			}
		} else {
			cout << -1 << '\n';
		}
	}
}
