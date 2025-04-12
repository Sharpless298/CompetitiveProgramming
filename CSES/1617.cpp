#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
		ans = ans * 2 % MOD;

	cout << ans << '\n';
}
