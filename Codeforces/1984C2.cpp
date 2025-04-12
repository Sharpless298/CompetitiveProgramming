#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> p(200001);
	p[0] = 1;
	for (int i = 1; i <= 200000; i++)
		p[i] = p[i - 1] * 2 % MOD;

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		long long sum = 0, mn = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			mn = min(mn, sum);
		}

		if (mn == 0) {
			cout << p[n] << '\n';
			continue;
		}

		int cnt = 0;
		long long ans = 0;
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (sum == mn)
				ans = (ans + p[n - i - 1 + cnt]) % MOD;
			if (sum >= 0)
				cnt++;
		}
		cout << ans << '\n';
	}
}
