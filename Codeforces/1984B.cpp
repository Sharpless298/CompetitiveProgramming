#include <iostream>
using namespace std;

typedef long long int lli;

lli x;

void solve() {
	cin >> x;

	x = x - x % 10 + (x % 10 + 1) % 10;
	while (x > 9) {
		if (x % 10 == 0) {
			cout << "NO\n";
			return;
		}
		x /= 10;
	}

	cout << (x == 1 ? "YES\n" : "NO\n");
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--)
		solve();
}
