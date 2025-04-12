#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

int p;
vector<lli> fact(100001), inv(100001), fact_inv(100001);

lli C(int n, int m) {
	if (m > n)
		return 0;
	return fact[n] * fact_inv[n - m] % p * fact_inv[m] % p;
}

lli Lucas(int n, int m) {
	if (m == 0)
		return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, n, m;

	cin >> T;
	while (T--) {
		cin >> n >> m >> p;

		fact[0] = 1;
		for (int i = 1; i <= n + m; i++)
			fact[i] = fact[i - 1] * i % p;
		inv[1] = 1;
		for (int i = 2; i <= n + m; i++)
			inv[i] = (p - p / i) * inv[p % i] % p;
		fact_inv[0] = 1;
		for (int i = 1; i <= n + m; i++)
			fact_inv[i] = fact_inv[i - 1] * inv[i] % p;

		cout << Lucas(n + m, n) << '\n';
	}
}
