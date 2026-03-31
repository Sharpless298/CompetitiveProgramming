#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 998244353;
const int N = 2000000;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int64_t> fact(N + 1);
	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	vector<int64_t> inv(N + 1);
	inv[1] = 1;
	for (int i = 2; i <= N; i++) {
		inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
	}
	vector<int64_t> fact_inv(N + 1);
	fact_inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		array<int, 4> c;
		for (int i = 0; i < 4; i++) {
			cin >> c[i];
		}
		if (c[0] == 0 && c[1] == 0) {
			if (c[2] == 0 || c[3] == 0) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
			continue;
		}

		if (abs(c[0] - c[1]) > 1) {
			cout << 0 << '\n';
			continue;
		}

		auto nCr = [&](int n, int r) -> int64_t {
			return fact[n] * fact_inv[r] % MOD * fact_inv[n - r] % MOD;
		};

		int64_t ans = 0;
		if (c[0] == c[1]) {
			int n = c[0];
			ans = (ans + nCr(c[2] + n - 1, n - 1) * nCr(c[3] + n, n)) % MOD;
			ans = (ans + nCr(c[2] + n, n) * nCr(c[3] + n - 1, n - 1)) % MOD;
		} else {
			int n = max(c[0], c[1]);
			ans = (ans + nCr(c[2] + n - 1, n - 1) * nCr(c[3] + n - 1, n - 1)) % MOD;
		}
		cout << ans << '\n';
	}
}
