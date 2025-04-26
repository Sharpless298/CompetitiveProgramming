#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n) {
		auto fac = [](int k) {
			long long res = 1;
			for (int i = 1; i <= k; i++)
				res = res * i % MOD;
			return res;
		};
		cout << fac(n / 2) * fac(n / 2) % MOD * (n & 1 ? n : 1) % MOD << '\n';
	}
}
