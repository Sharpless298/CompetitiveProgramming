#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

vector<lli> fact(200001), inv(200001), fact_inv(200001);

lli C(int n, int m) {
	return fact[n] * fact_inv[n - m] % MOD * fact_inv[m] % MOD;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, W, A, B;

	fact[0] = 1;
	for (int i = 1; i <= 200000; i++)
		fact[i] = fact[i - 1] * i % MOD;
	inv[1] = 1;
	for (int i = 2; i <= 200000; i++)
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	fact_inv[0] = 1;
	for (int i = 1; i <= 200000; i++)
		fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;

	cin >> H >> W >> A >> B;

	lli ans = 0;
	for (int i = 0; i < H - A; i++)
		ans = (ans + C(B - 1 + i, i) * C((W - B - 1) + (H - i - 1), H - i - 1)) % MOD;

	cout << ans << '\n';
}
