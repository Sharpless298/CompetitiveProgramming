#include <algorithm>
#include <iostream>
using namespace std;

int ary[505];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc, ans, n, med;

	cin >> tc;

	while (tc--) {
		ans = 0;

		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ary[i];

		sort(ary, ary + n);
		med = ary[n / 2];
		for (int i = 0; i < n; i++)
			ans += abs(med - ary[i]);

		cout << ans << '\n';
	}
}
