#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0, x; i < T; i++) cin >> x;

	vector<int> k(T);
	for (int &i : k) cin >> i;

	auto modpow = [](int b) {
		long long res = 1, a = 2;
		while (b) {
			if (b & 1) res = res * a % MOD;
			a = a * a % MOD, b >>= 1;
		}
		return res;
	};

	for (int i = 0; i < T; i++)
		cout << modpow(k[i]) << '\n';
}
