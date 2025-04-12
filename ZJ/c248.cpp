#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	vector<lli> inv(1148581);
	inv[1] = 1;
	for (int i = 2; i <= 1148576; i++)
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	vector<lli> f(1148581);
	f[0] = 1;
	for (int i = 1; i <= 1148575; i++)
		f[i] = f[i - 1] * (4 * i - 2) % MOD * inv[i + 1] % MOD;

	cin >> T;
	while (T--) {
		int n;

		cin >> n;

		cout << f[n] << '\n';
	}
}
