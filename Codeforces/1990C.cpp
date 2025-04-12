#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int lli;

int n;
vector<bool> c(200005);
vector<int> a(200005);

void f() {
	int mx = 0;

	for (int i = 1; i <= n; i++)
		c[i] = false;

	for (int i = 0; i < n; i++) {
		if (c[a[i]])
			mx = max(mx, a[i]);

		c[a[i]] = true;
		a[i] = mx;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--) {
		lli ans = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < n; i++)
			ans += a[i];
		f();
		for (int i = 0; i < n; i++)
			ans += a[i];
		f();
		for (int i = 0; i < n; i++)
			ans += 1LL * (n - i) * a[i];

		cout << ans << '\n';
	}
}
