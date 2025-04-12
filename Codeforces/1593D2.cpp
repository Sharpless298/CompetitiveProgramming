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

		auto divs = [&](int x) -> vector<int> {
			vector<int> d;
			for (int i = 1; i * i <= x; i++) {
				if (x % i == 0) {
					d.push_back(i);
					if (x / i != i)
						d.push_back(x / i);
				}
			}
			return d;
		};
		int ans = -1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			vector<int> v;
			for (int j : a) {
				if (j == a[i])
					cnt++;
				else if (j > a[i])
					v.push_back(j - a[i]);
			}
			if (cnt >= n / 2) {
				ans = 0x3f3f3f3f;
				continue;
			}

			map<int, int> mp;
			for (int j : v)
				for (int d : divs(j))
					mp[d]++;

			for (auto p : mp)
				if (p.second >= n / 2 - cnt)
					ans = max(ans, p.first);
		}

		cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
	}
}
