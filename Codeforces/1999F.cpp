#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> fact(200001), inv(200001), inv_fact(200001);

long long nCr(int n, int k) {
	return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = 1;
	for (int i = 1; i <= 200000; i++)
		fact[i] = fact[i - 1] * i % MOD;
	inv[1] = 1;
	for (int i = 2; i <= 200000; i++)
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	inv_fact[0] = 1;
	for (int i = 1; i <= 200000; i++)
		inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;

		int cnt0 = 0, cnt1 = 0;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] == 1 ? cnt1++ : cnt0++;
		}

		long long ans = 0;
		for (int i = (k + 1) / 2; i <= k; i++) {
			if (cnt0 < k - i || cnt1 < i)
				continue;
			ans = (ans + nCr(cnt0, k - i) * nCr(cnt1, i)) % MOD;
		}

		cout << ans << '\n';
	}
}
