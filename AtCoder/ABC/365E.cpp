#include <bits/stdc++.h>
using namespace std;

const int LOG = 27;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;

	long long ans = 0;
	for (int i = 0; i < LOG; i++) {
		vector<int> b(n + 1);
		b[0] = 0;
		for (int j = 0; j < n; j++)
			b[j + 1] = b[j] ^ (a[j] >> i & 1);

		vector<int> cnt(2);
		for (int j = 0; j <= n; j++)
			cnt[b[j]]++;

		ans += (1LL << i) * cnt[0] * cnt[1];
	}
	ans -= accumulate(a.begin(), a.end(), 0LL);

	cout << ans << '\n';
}
