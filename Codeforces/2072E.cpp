#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> sum(10001);
	sum[0] = 0;
	for (int i = 1; i <= 10000; i++)
		sum[i] = sum[i - 1] + i;

	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> k;

		int x = (int)1e-8, y = (int)1e-8;
		vector<pair<int, int>> ans;
		while (k) {
			int t = 1;
			while (sum[t + 1] <= k)
				t++;
			for (int i = 0; i <= t; i++)
				ans.push_back(make_pair(x, y + i));
			k -= sum[t];
			x += 298, y += 471;
		}

		cout << ans.size() << '\n';
		for (pair<int, int> p : ans)
			cout << p.first << ' ' << p.second << '\n';
	}
}
