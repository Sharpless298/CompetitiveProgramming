#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n, m, k;
		cin >> n >> m >> k;

		int p = max(n, m), q = min(n, m);
		if (p < k || p - q > k) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> ans;
		for (int i = 0; i < k; i++)
			ans.push_back(0);
		p -= k;
		int c = p + q;
		for (int i = 0; i < c; i++) {
			if (i & 1 && p)
				ans.push_back(0), p--;
			else
				ans.push_back(1);
		}
		if (n < m)
			for (int &i : ans)
				i = !i;

		for (int i : ans)
			cout << i;
		cout << '\n';
	}
}
