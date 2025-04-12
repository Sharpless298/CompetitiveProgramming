#include <iostream>
using namespace std;

typedef long long int lli;

int a[200005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, mx;
	lli ans = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mx = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < mx)
			ans += mx - a[i];
		mx = max(mx, a[i]);
	}

	cout << ans << '\n';
}
