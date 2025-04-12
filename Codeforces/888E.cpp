#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	auto f = [&](int l, int r) -> vector<int> {
		int len = r - l + 1;
		vector<int> res;
		for (int i = 0; i < (1 << len); i++) {
			int sum = 0;
			for (int j = 0; j < len; j++)
				if (i & (1 << j))
					sum = (sum + a[l + j]) % m;
			res.push_back(sum);
		}
		return res;
	};
	vector<int> l = f(0, n / 2), r = f(n / 2 + 1, n - 1);
	sort(l.begin(), l.end(), greater<int>());
	sort(r.begin(), r.end());

	int ans = 0;
	for (int i = 0, j = 0; i < (int)l.size(); i++)
		while (j < (int)r.size() && l[i] + r[j] < m)
			ans = max(ans, (l[i] + r[j]) % m), j++;

	cout << ans << '\n';
}
