#include <iostream>
using namespace std;

typedef long long int lli;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	lli n, k;

	cin >> T;
	while (T--) {
		cin >> n >> k;

		cout << k + (k - 1) / (n - 1) << '\n';
	}
}
