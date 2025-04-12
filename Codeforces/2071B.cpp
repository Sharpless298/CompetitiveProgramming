#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> perfect(500001);
	auto f = [](long long x) {
		long long l = 1, r = x + 1;
		while (l < r) {
			long long m = (l + r) / 2;
			if (m > 500000 || m * m > x)
				r = m;
			else if (m * m < x)
				l = m + 1;
			else
				return true;
		}
		return false;
	};
	for (long long i = 1; i <= 500000; i++)
		perfect[i] = f((1 + i) * i / 2);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		if (perfect[n]) {
			cout << -1 << '\n';
			continue;
		}

		vector<int> ans(n);
		iota(ans.begin(), ans.end(), 1);
		for (int i = 1; i < n; i++)
			if (perfect[i])
				swap(ans[i - 1], ans[i]);

		for (int x : ans)
			cout << x << ' ';
		cout << '\n';
	}
}
